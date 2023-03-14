#include "BB.hpp"


BB::BB(int _id) : id(_id), printed(false) {
    true_exit = nullptr;
    false_exit = nullptr;
}

string BB::getName() {
    string blockName = "Block_" + to_string(id);
    return blockName;
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

void BB::first_pos_tac(Tac* tac) {
    this->tac_instructions.insert(tac_instructions.begin(), tac);
}

string BB::generate_name(int id) const {
    return "temporary_" + to_string(id);
}

string& BB::getMethodName() {
    return this->method_name;
}
void BB::setMethodName(string _method_name) {
    this->method_name = _method_name;
}

/*Associated to Part 2 */
void BB::generate_code(vector<InstructionBC*> &bc) {
    /*For given block, generate code from tacs in block's tac instructions*/
    for (auto const& tac : tac_instructions) {
        tac->generate_code(bc);
    }
}


