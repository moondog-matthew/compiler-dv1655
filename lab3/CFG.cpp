
#include "CFG.hpp"

CFG::CFG() {

}

CFG::CFG(Node* node) {
    populate_CFG(node);
    // Create first program block
}

void CFG::print_CFG() {
    entry->generate_BB();
}

void CFG::populate_CFG(Node* node) {
    node->genIR(entry, methods, BBnames);
}