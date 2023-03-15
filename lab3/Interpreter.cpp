#include "Interpreter.hpp"

const int Activation::getPC() const {
    return this->pc;
}

const MethodBC* Activation::getMethod() const {
    return this->method;
}

const vector<string>& Activation::getLocalVar() const {
    return this->local_variable_values;
}

Interpreter::Interpreter(ProgramBC* _pbc) {
    this->pbc = _pbc;
    assignMain();
}

const ProgramBC* Interpreter::getPBC() const {
    return this->pbc;
}
const MethodBC* Interpreter::getMain() const {
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

}