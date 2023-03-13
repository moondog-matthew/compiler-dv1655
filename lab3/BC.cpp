#include "BC.hpp"


InstructionBC::InstructionBC(int _id, string _instruction_argument) 
    : id(_id), instruction_argument(_instruction_argument) {}
InstructionBC::~InstructionBC() {}
void InstructionBC::print() const {
}

MethodBC::MethodBC(vector<string> &_variables, vector<InstructionBC*> &_instructions, string _block_name) 
    : variables(_variables), instructions(_instructions), block_name(_block_name) {}
MethodBC::~MethodBC() {}
void MethodBC::print() const {

}
ProgramBC::ProgramBC() {}
ProgramBC::~ProgramBC() {}
void ProgramBC::print() const {
    int bc_vec_sz = bc_methods.size();
    int qual_meth_vec = qual_method_names.size();
    cout << bc_vec_sz << endl;
    cout << qual_meth_vec << endl;
    if (bc_vec_sz == qual_meth_vec) {
        cout << "Same" << endl;
    }
}
void ProgramBC::add_method(MethodBC* meth) {
    this->bc_methods.push_back(meth);
}

void ProgramBC::add_qual_name(pair<string, string> name_pair) {
    this->qual_method_names.push_back(name_pair);
}
