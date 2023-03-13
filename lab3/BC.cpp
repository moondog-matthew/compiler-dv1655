#include "BC.hpp"


InstructionBC::InstructionBC(int _id, string _instruction_argument) : id(_id), instruction_argument(_instruction_argument) {}
InstructionBC::~InstructionBC() {}
void InstructionBC::print() const {

}

MethodBC::MethodBC(vector<string> &_variables, vector<InstructionBC*> &_instructions) : variables(_variables), instructions(_instructions) {}
MethodBC::~MethodBC() {}
void MethodBC::print() const {

}
ProgramBC::ProgramBC(std::map<string, string> &_qual_method_names) : qual_method_names(_qual_method_names) {}
ProgramBC::~ProgramBC() {}
void ProgramBC::print() const {

}