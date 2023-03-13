#include "BC.hpp"


InstructionBC::InstructionBC(int _id, string _instruction_argument) : id(_id), instruction_argument(_instruction_argument) {}
InstructionBC::~InstructionBC() {}
void InstructionBC::print() const {

}

MethodBC::MethodBC(vector<string> &_variables, vector<InstructionBC*> &_instructions) : variables(_variables), instructions(_instructions) {}
MethodBC::~MethodBC() {}
void MethodBC::print() const {

}
ProgramBC::ProgramBC(std::map<string, string> &_qual_method_names, vector<MethodBC*> &_bc_methods) : qual_method_names(_qual_method_names), bc_methods(_bc_methods)  {}
ProgramBC::~ProgramBC() {}
void ProgramBC::print() const {

}
void ProgramBC::add_method(MethodBC* meth) {
    this->bc_methods.push_back(meth);
}

void ProgramBC::add_qual_name(pair<string, string> name_pair) {
    this->qual_method_names.insert(name_pair);
}