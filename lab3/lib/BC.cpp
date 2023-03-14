#include "BC.hpp"


InstructionBC::InstructionBC(int _id, string _instruction_argument) 
    : id(_id), instruction_argument(_instruction_argument) {}
InstructionBC::~InstructionBC() {}
void InstructionBC::print(ofstream* outStream) const {
    *outStream << instruction_argument << "\n";
}

MethodBC::MethodBC(vector<string> &_variables, vector<InstructionBC*> &_instructions, string _block_name) 
    : variables(_variables), instructions(_instructions), block_name(_block_name) {}
MethodBC::~MethodBC() {}
void MethodBC::print(ofstream* outStream) const {
    for (auto const& instruction : instructions) {
        instruction->print(outStream);
    }
}

ProgramBC::ProgramBC() {}
ProgramBC::~ProgramBC() {}
void ProgramBC::print() const {
    std:ofstream outStream;
	char* filename = "program.out"; // Outfile name
	outStream.open(filename);
    int bc_vec_sz = bc_methods.size();
    int qual_meth_vec = qual_method_names.size();
    if (bc_vec_sz == qual_meth_vec) {
        for (int i = 0; i < bc_vec_sz; ++i) {
            outStream << qual_method_names[i].first + "." + qual_method_names[i].second << "\n";
            bc_methods[i]->print(&outStream);
        }
    }
    else {
        cout << "ERROR!!! bc_vec_sz and qual_meth_vec is not of same size" << endl;
    }
    outStream.close();
}



void ProgramBC::add_method(MethodBC* meth) {
    this->bc_methods.push_back(meth);
}

void ProgramBC::add_qual_name(pair<string, string> name_pair) {
    this->qual_method_names.push_back(name_pair);
}
