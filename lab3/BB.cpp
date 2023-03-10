#include "BB.hpp"

BB::BB() {
    true_exit = nullptr;
    false_exit = nullptr;
    jumpBlock = nullptr;
}

string& BB::getName() {
    return this->name;
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


string BB::generate_name(int id) const {
    return "temporary_" + to_string(id);
}