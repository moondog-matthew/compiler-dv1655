#include "BB.hpp"

BB::BB() {
    true_exit = nullptr;
    false_exit = nullptr;
}

string& BB::getName() {
    return this->name;
}
std::vector<Tac*>& BB::getInstructions() {
    return this->tac_instructions;
}
Tac* BB::getCondition() {
    return this->condition;
}
BB* BB::getFalse() {
    return this->false_exit;
}
BB* BB::getTrue() {
    return this->true_exit;
}
void BB::setFalse(BB* falseChild) {
    this->false_exit = falseChild;
}
void BB::setTrue(BB* trueChild) {
    this->true_exit = trueChild;
}

void BB::add_Tac(Tac* tac) {
    this->tac_instructions.push_back(tac);
}

void BB::generate_BB() {
	std:ofstream outStream;
	char* filename = "CFG-tree.dot"; // Outfile name
	outStream.open(filename);
	int count = 0;
	outStream << "digraph {" << "\n";
    outStream << "graph [ splines = ortho ]\n\tnode [ shape = box ];" << "\n";
	generate_BB_content(count, &outStream);
	outStream << "}" << endl;
	outStream.close();
	printf("\nBuilt a parse-tree at %s. Use 'make cfg-tree' to generate the pdf version.\n", filename);
}

void BB::generate_BB_content(int &count, ofstream *outStream) {
	id = count++;
    *outStream << "block_" << id << " [label=\"" << "Block" << ":" << getName();
    for(const auto& tac : tac_instructions) {
        *outStream << "\n" << tac->printTac();
    }
    *outStream << "\"];" << "\n"; 
    if (true_exit != nullptr) {
        true_exit->generate_BB_content(count, outStream);
        *outStream << "block_" << id << " -> block_" << true_exit->id << " [xlabel = \"true\"]" << endl ;
    }
    if (false_exit != nullptr) {
        false_exit->generate_BB_content(count, outStream);
        *outStream << "block_" << id << " -> block_" << false_exit->id << " [xlabel = \"false\"]" << endl ;
    }

}