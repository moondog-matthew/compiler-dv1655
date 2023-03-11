#include "CFG.hpp"

CFG::CFG() {

}

CFG::CFG(Node* node) {
    this->entry = new BB(0);
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
    node->genIR(&entry, methods, BBnames, val);

    // for (auto const& block : methods) {
    //     if (block->getTrue() == nullptr || block->getTrue() == block) {
    //         cout << block->getName() << "Problem?" << endl;
    //     }
    // }
}