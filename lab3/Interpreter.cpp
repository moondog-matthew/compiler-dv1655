#include "Interpreter.hpp"

Activation::Activation() {}

int Activation::getPC() const {
    return this->pc;
}

MethodBC* Activation::getMethod() const {
    return this->method;
}

InstructionBC* Activation::getNextInstruction() const {

}

vector<string>& Activation::getLocalVar() {
    return this->local_variable_values;
}

Interpreter::Interpreter(ProgramBC* _pbc) {
    this->pbc = _pbc;
    assignMain();
}

ProgramBC* Interpreter::getPBC() const {
    return this->pbc;
}
MethodBC* Interpreter::getMain() const {
    return this->main;
}

void Interpreter::assignMain() {
    for (auto const& meth : pbc->getBCmethods()) {
        // match all class methods with ".main" ending
        if (regex_match(meth->get_name(), regex("(.*)(\\.main)")) ) { 
            this->main = meth;
        }
    }
}

void Interpreter::execute() {
    Activation* current_activation = new Activation();
    InstructionBC* instruction;
    int instruction_id = -1;
    // Create stack
    // Stack activation_stack = new Stack()

    while(instruction_id != 18) { // id = stop
        instruction = current_activation->getNextInstruction();
        switch (instruction->getID())
        {
        case 0:
            /* ILOAD */
            break;
        case 1:
            /* ICONST */
            break;
        case 2:
            /* */
            break;
        default:
            break;
        }
    }
}