
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
    *outStream << "block_" << id << " [label=\"" << "Block" << ":" << block->getName();
    for(const auto& tac : block->getInstructions()) {
        *outStream << "\n" << tac->printTac();
    }
    *outStream << "\"];" << "\n"; 
    if (block->getTrue() != nullptr) {
        generate_CFG_content(block->getTrue(), count, outStream);
        *outStream << "block_" << id << " -> block_" << id << " [xlabel = \"true\"]" << endl ;
    }
    if (block->getFalse() != nullptr) {
        generate_CFG_content(block->getFalse(), count, outStream);
        *outStream << "block_" << id << " -> block_" << id << " [xlabel = \"false\"]" << endl ;
    }
}

void CFG::populate_CFG(Node* node) {
    node->genIR(&entry, methods, BBnames);
}