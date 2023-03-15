#include "Interpreter.hpp"

Activation::Activation(MethodBC* _method) : method(_method) {
    index = -1; // index to 0; Can we always expect that 
} 

int Activation::getPC() const {
    return this->pc;
}

MethodBC* Activation::getMethod() const {
    return this->method;
}

InstructionBC* Activation::getNextInstruction() {
    if (method->getInstructions().empty()) {
        return nullptr; // if no instructions
    }
    this->index += 1; // index starts at -1 
    return method->getInstructions()[index];
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
    Activation* current_activation = new Activation(main);
    InstructionBC* instruction;
    int instruction_id = -1;
    // Create stack
    // Stack activation_stack = new Stack()

    while(instruction_id != 18) { // id = stop
        instruction = current_activation->getNextInstruction();
        instruction_id = instruction->getID();
        switch (instruction_id)
        {
        case 0:
            /* iload n */
            instruction->stdio_out();
            break;
        case 1:
            /* iconst v */
            instruction->stdio_out();
            break;
        case 2:
            /* istore n */
            instruction->stdio_out();
            break;
        case 3:
            /* iadd */
            instruction->stdio_out();
            break;
        case 4:
            /* isub */
            instruction->stdio_out();
            break;
        case 5:
            /* imul */
            instruction->stdio_out();
            break;
        case 6:
            /* idiv */
            instruction->stdio_out();
            break;
        case 7:
            /* igt */
            instruction->stdio_out();
            break;
        case 8:
            /* ilt */
            instruction->stdio_out();
            break;
        case 9:
            /* ieq */
            instruction->stdio_out();
            break;
        case 10:
            /* ior */
            instruction->stdio_out();
            break;
        case 11:
            /* iand */
            instruction->stdio_out();
            break;
        case 12:
            /* inot */
            instruction->stdio_out();
            break;
        case 13:
            /* goto i */
            instruction->stdio_out();
            break;
        case 14:
            /* iffalse goto i */
            instruction->stdio_out();
            break;
        case 15:
            /* invokevirtual m */
            instruction->stdio_out();
            break;
        case 16:
            /* ireturn */
            instruction->stdio_out();
            break;
        case 17:
            /* print */
            instruction->stdio_out();
            break;
        case 18:
            /* stop */
            instruction->stdio_out();
            break;
        case 19:
            /* label */
            instruction->stdio_out();
        default:
            break;
        }
    }
}