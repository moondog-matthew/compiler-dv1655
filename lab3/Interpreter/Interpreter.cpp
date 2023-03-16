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

int Activation::findLabel(string label) {
    /*
        For given label return index in which label can be found
    */
    int size = method->getInstructions().size();
    string regexstring = "("+ label + ":)";
    for (int i = 0; i < size; ++i) {
        if (regex_match(method->getInstructions()[i]->getInstructionArgument(), regex(regexstring))) {
            return i;
        }
    }
    return -1; // if not found
}

void Activation::setIndex(int _index) {
    this->index = _index;
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
    activation_stack.push_back(current_activation);
    InstructionBC* instruction;
    int instruction_id = -1;
    string tmp;
    int val1;
    int val2;
    int index;
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
            if (current_activation->varExists(tmp)) {
                current_activation->updateVariable(tmp, val1);
            }
            else {
                current_activation->addVariable(tmp, val1);  // if already exists, will overwrite value. Intended behaviour.
            }
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
                6.2 else push 0
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
                6.2 else push 0
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
            /* 
                ieq
                1. get val1 from data stack
                2. pop value from data stack
                3. get val2 from data stack
                4. pop value from data stack
                5. compare values, 
                6.1 if val2 == val1: push 1 to stack
                6.2 else push 0
            */
            val1 = data_stack.back();
            data_stack.pop_back();
            val2 = data_stack.back();
            data_stack.pop_back();
            if (val2 == val1) {
                data_stack.push_back(1);
            }
            else {
                data_stack.push_back(0);
            }
            break;
        case 10:
            /* 
                ior
                1. get val1 from data stack
                2. pop value from data stack
                3. get val2 from data stack
                4. pop value from data stack
                5. compare values, 
                6.1 if val2 + val1 == 0: push 0 to stack
                6.2 else push 1
            */
            val1 = data_stack.back();
            data_stack.pop_back();
            val2 = data_stack.back();
            data_stack.pop_back();
            if (val2 + val1 == 0) {
                data_stack.push_back(0);
            }
            else {
                data_stack.push_back(1);
            }
            break;
        case 11:
            /* 
                iand
                1. get val1 from data stack
                2. pop value from data stack
                3. get val2 from data stack
                4. pop value from data stack
                5. compare values, 
                6.1 if val2 * val1 == 0: push 0 to stack
                6.2 else push 1
            */
            val1 = data_stack.back();
            data_stack.pop_back();
            val2 = data_stack.back();
            data_stack.pop_back();
            if (val2 * val1 == 0) {
                data_stack.push_back(0);
            }
            else {
                data_stack.push_back(1);
            }
            break;
        case 12:
            /* 
                inot
                1. get v from data stack
                2. pop value from data stack
                3.1 if val1 == 0: push 1 to stack. I.e, just reverse boolean condition.
                3.2 else push 0
            */
            cout << "Enters" << endl;
            val1 = data_stack.back();
            data_stack.pop_back();
            if (val1 == 0) {
                data_stack.push_back(1);
            }
            else {
                data_stack.push_back(0);
            }
            break;
        case 13:
            /* 
                goto i
                1. get i part of instruction
                2. search for the label i in the method instructions. (from start to finish)
                3. Retrieve the index in which it is stored. 
                4. Set the methodBC index to that index. Hence next instruction will be from there
            */
            tmp = second_half_string(instruction->getInstructionArgument());
            index = current_activation->findLabel(tmp);
            current_activation->setIndex(index);
            break;
        case 14:
            /* 
                iffalse goto i
                1. get i part of string 
                2. pop bool from stack
                3.1 if true (1), do nothing
                3.2 if false (0), get index and set current->actication index to that label
            */
            tmp = second_half_string(instruction->getInstructionArgument()); // fetches i, places in tmp
            val1 = data_stack.back();
            data_stack.pop_back();
            if (val1 == 0) {
                // false
                index = current_activation->findLabel(tmp);
                current_activation->setIndex(index);
            }
            // else do nothing
            break;
        case 15:
            /* 
                invokevirtual m 
                1. create new activation with next method in pbc
                2. add the new activation to the activation stack 
            */
            current_activation = new Activation(pbc->getNextBCmethod());
            activation_stack.push_back(current_activation);
            break;
        case 16:
            /* 
                ireturn
                1. pop the top activation on the activation stack
                2. Set the new top to the current activation 
            */
            delete current_activation; // free memory
            activation_stack.pop_back(); // remove top
            current_activation = activation_stack.back();
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
            break;
        case 18:
            /* stop */
            instruction->stdio_out();
            break;
        case 19:
            /* label */
            // instruction->stdio_out();
            break;
        default:
            break;
        }
    }
}