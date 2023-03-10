#include "CFG.hpp"

CFG::CFG() {

}

CFG::CFG(Node* node) {
    this->entry = new BB();
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
	printf("\nBuilt a parse-tree at %s. Use 'make cfg-tree' to generate the pdf version.\n", filename);
}

void CFG::generate_CFG_content(BB* block, int &count, ofstream *outStream) {
    int id = count++;
    printedBlocks.push_back(block->getName());
    *outStream << "block_" << id << " [label=\"" << "Block" << ":" << block->getName();
    for(const auto& tac : block->getInstructions()) {
        *outStream << "\n" << tac->printTac();
    }
    *outStream << "\"];" << "\n"; 
    if (block->getTrue() != nullptr) {
        *outStream << "block_" << id << " -> block_" << id << " [xlabel = \"true\"]" << endl ;
        if (std::find(printedBlocks.begin(), printedBlocks.end(), block->getTrue()->getName()) == printedBlocks.end()) {
            generate_CFG_content(block->getTrue(), count, outStream);
        }
    }
    if (block->getFalse() != nullptr) {
        generate_CFG_content(block->getFalse(), count, outStream);
        *outStream << "block_" << id << " -> block_" << id << " [xlabel = \"false\"]" << endl ;
    }
}

void CFG::populate_CFG(Node* node) {
    methods.push_back(entry);
    int val = 0;
    node->genIR(entry, methods, BBnames, val);

    for (auto const& meth : methods) {
        for (auto const& tac : meth->getInstructions()) {
            cout << tac->printTac() << endl;
        }
    }

}