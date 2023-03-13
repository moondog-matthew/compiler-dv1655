#include "CFG.hpp"

CFG::CFG() {

}

CFG::CFG(Node* node, SymbolTable* _ST) {
    this->entry = new BB(0);
    this->ST = _ST;
    populate_CFG(node);
}

void CFG::generate_CFG() {
    std:ofstream outStream;
	char* filename = "CFG-tree.dot"; // Outfile name
	outStream.open(filename);
	int count = 0;
	outStream << "digraph {" << "\n";
    outStream << "graph [ splines = ortho ]\n\tnode [ shape = box ];" << "\n";
	for (auto const& method : methods) {
        generate_CFG_content(method, count, &outStream);
    }
	outStream << "}" << endl;
	outStream.close();
	printf("\nBuilt a parse-tree at %s. Use 'make cfg-tree' to generate the pdf version.\n\n", filename);
}

void CFG::generate_CFG_content(BB* block, int &count, ofstream *outStream) {
    int id = count++;
    printedBlocks.push_back(block->getName());
    *outStream << block->getName() << " [label=\"" << "Block" << ":" << block->getName();
    
    // Print Tacs in block
    for(const auto& tac : block->getInstructions()) {
        *outStream << "\n" << tac->printTac();
    }
    *outStream << "\"];" << "\n"; 

    // Print true and false pointers
    if (block->getTrue() != nullptr) {
        *outStream << block->getName() << " -> " << block->getTrue()->getName() << " [xlabel = \"true\"]" << endl ;
        if (std::find(printedBlocks.begin(), printedBlocks.end(), block->getTrue()->getName()) == printedBlocks.end()) {
            generate_CFG_content(block->getTrue(), count, outStream);
        }
    }
    if (block->getFalse() != nullptr) {
        *outStream << block->getName() << " -> " << block->getFalse()->getName() << " [xlabel = \"false\"]" << endl ;
        generate_CFG_content(block->getFalse(), count, outStream);
    }
}

void CFG::populate_CFG(Node* node) {
    methods.push_back(entry);
    int val = 0;
    int blockID = 1;
    node->genIR(&entry, methods, BBnames, val, blockID);

    // add temporary variables to ST
    for (auto const& namePair : BBnames) {
    // pair <string, string> namePair;  (name, type)
        variableRecord* varrec = new variableRecord(namePair.first, namePair.second, 0); // lineno just set to arbitrary value
        ST->add_symbol(varrec);
    }
}

ProgramBC* CFG::generate_BC() {
    std::map<string, string> qual_method_names; 
    vector<MethodBC*> bc_methods;
    ProgramBC* progbc = new ProgramBC(qual_method_names, bc_methods);
    
    for (auto const& bb : methods) { 
        // fill the instructions and variables vector
        vector<InstructionBC*> instructions; 
        vector <string> variables;
        bb->generate_code(instructions);  
        MethodBC* methbc = new MethodBC(variables, instructions); 
        // add the method to the programbc
        progbc->add_method(methbc); // add the method to the programbc
        /* addd qualified method names*/
        
    }
    /* 
        Fill map of qualified method names
    */
    string class_name; // somehow find class name
    string method_name; // somehow find method name
    for(auto const& program_class : ST->get_root_scope()->children) {
        Record* classrec = program_class->lookup("this", 0);
        class_name = classrec->name;
        for (auto const& child : program_class->inScopeRecords) {
            if (child->recordType == "Method") {
                method_name = child->name;
                progbc->add_qual_name(pair<string, string>(class_name, method_name));

            }
        }
    }

    return progbc;
}

