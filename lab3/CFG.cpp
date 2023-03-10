
#include "CFG.hpp"

CFG::CFG() {

}

CFG::CFG(Node* node) {
    this->entry = new BB();
    populate_CFG(node);
}

void CFG::print_CFG() {
    entry->generate_BB();
}

void CFG::populate_CFG(Node* node) {
    node->genIR(&entry, methods, BBnames);
}