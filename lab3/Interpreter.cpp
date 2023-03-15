#include "Interpreter.hpp"

Activation::Activation(MethodBC* _method) : method(_method) {
    index = -1; // index to 0; Can we always expect that 
} 

int Activation::getPC() const {
    return this->pc;
}

map<string, int>& Activation::getLocalVar() {
    return this->local_variable_values;
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

void Activation::addVariable(string variable_name, int i) {
    /*
        Add variable with value to local_variable_values
    */
    this->local_variable_values.insert(pair<string, int>(variable_name, i));
}
void Activation::updateVariable(string variable_name, int newval) {
    /*
        Finds if key in map exists
        If exists, update its value
    */
    map<string, int>::iterator it = this->local_variable_values.find(variable_name);
    if (it != local_variable_values.end()) {
        it->second = newval;
    }
}

int Activation::getLocalValue(string key) {
    /*
        1. Finds key
        2. Return key value
        3. Should never return -1, if so program error
    */
    map<string, int>::iterator it = this->local_variable_values.find(key);
    if (it != local_variable_values.end()) {
        return it->second;
    }
    return -1;
}

bool Activation::varExists(string key) {
    /*
        Checks if a variable exists in local_variable_values
        if exists: return true
        if not: return false
    */
    map<string, int>::iterator it = this->local_variable_values.find(key);
    if (it != local_variable_values.end()) {
        return true;
    }
    return false;
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

string Interpreter::second_half_string(string orig) {
    string second_half;
    stringstream ss(orig);
    while(ss >> second_half) {}
    return second_half;
}

void Interpreter::execute() {
    Activation* current_activation = new Activation(main);
    InstructionBC* instruction;
    int instruction_id = -1;
    string tmp;
    int val1;
    int val2;
    /*
        Create stack
            1. Data stack, dont need to be initialized, stored in interpreter class
            2. Activation stack: needs initialization, stored in interpreter class
    */ 
    // Stack* activation_stack = new Stack()

    while(instruction_id != 18) { // id = stop
        instruction = current_activation->getNextInstruction();
        instruction_id = instruction->getID();
        
        switch (instruction_id)
        {
        case 0:
            /* 
                iload n
                1. Get n of the instruction, store in tmp
                2.  Check if variable already exists
                3.1 If exists, fetch its value and place in v
                3.2 If not, addVariable to vector, take default value 0
                4. add v to the data stack 
            */
            tmp = second_half_string(instruction->getInstructionArgument());
            if (current_activation->varExists(tmp)) {
                val1 = current_activation->getLocalValue(tmp);
            }
            else {
                current_activation->addVariable(tmp);
                val1 = 0;
            }
            data_stack.push_back(val1);
            break;
        case 1:
            /* 
                iconst v
                1. Get v part of instruction, integer constant
                2. push v to the data stack
            */
            tmp = second_half_string(instruction->getInstructionArgument());
            val1 = stoi(tmp);
            data_stack.push_back(val1);
            break;
        case 2:
            /* 
                istore n
                1. Get n part of instruction
                2. Store the last value (top of stack) in v
                3. pop value from stack (data stack)
                4. place in variable n
            */
            tmp = second_half_string(instruction->getInstructionArgument());
            val1 = data_stack.back(); // access last element in vector
            data_stack.pop_back();
            current_activation->addVariable(tmp, val1);  // if already exists, will overwrite value. Intended behaviour.
            break;
        case 3:
            /* 
                iadd 
                1. get val1 from data stack
                2. pop value from data stack
                3. get val2 from data stack
                4. pop value from data stack
                5. Add values, store in val1
                6. push val1 to the data stack
            */
            val1 = data_stack.back();
            data_stack.pop_back();
            val2 = data_stack.back();
            data_stack.pop_back();
            val1 = val1 + val2;
            data_stack.push_back(val1);
            break;
        case 4:
            /* 
                isub 
                1. get val1 from data stack
                2. pop value from data stack
                3. get val2 from data stack
                4. pop value from data stack
                5. subtract values, store in val1. because val2 is added to stack first (precedence).
                6. push val1 to the data stack
            */
            val1 = data_stack.back();
            data_stack.pop_back();
            val2 = data_stack.back();
            data_stack.pop_back();
            val1 = val2 - val1;
            data_stack.push_back(val1);
            break;
        case 5:
            /* 
                imul 
                1. get val1 from data stack
                2. pop value from data stack
                3. get val2 from data stack
                4. pop value from data stack
                5. multiply values, store in val1
                6. push val1 to the data stack
            */
            val1 = data_stack.back();
            data_stack.pop_back();
            val2 = data_stack.back();
            data_stack.pop_back();
            val1 = val1 * val2;
            data_stack.push_back(val1);
            break;
        case 6:
            /* 
                idiv 
                1. get val1 from data stack
                2. pop value from data stack
                3. get val2 from data stack
                4. pop value from data stack
                5. Divide values, store in val1. val2 / val1, because val2 is added to stack first (precedence).
                6. push val1 to the data stack
            */
            val1 = data_stack.back();
            data_stack.pop_back();
            val2 = data_stack.back();
            data_stack.pop_back();
            val1 = val2 / val1;
            data_stack.push_back(val1);
            break;
        case 7:
            /* 
                igt
                1. get val1 from data stack
                2. pop value from data stack
                3. get val2 from data stack
                4. pop value from data stack
                5. compare values, 
                6.1 if val2 > val1: push 1 to stack
                6.2 else push 2
            */
            val1 = data_stack.back();
            data_stack.pop_back();
            val2 = data_stack.back();
            data_stack.pop_back();
            if (val2 > val1) {
                data_stack.push_back(1);
            }
            else {
                data_stack.push_back(0);
            }
            break;
        case 8:
            /* 
                ilt
                1. get val1 from data stack
                2. pop value from data stack
                3. get val2 from data stack
                4. pop value from data stack
                5. compare values, 
                6.1 if val2 < val1: push 1 to stack
                6.2 else push 2
            */
            val1 = data_stack.back();
            data_stack.pop_back();
            val2 = data_stack.back();
            data_stack.pop_back();
            if (val2 < val1) {
                data_stack.push_back(1);
            }
            else {
                data_stack.push_back(0);
            }
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
            /* 
                print
                1. fetch the value on top of stack
                2. pop value from data stack
                3. print out value popped
            */
            val1 = data_stack.back();
            data_stack.pop_back();
            cout << "Program output: " << val1 << endl;
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