#include "semanticCheck.hpp"

SemanticAnalysis::SemanticAnalysis(Node* ast, SymbolTable* st) {
    this->AST_root = ast;
    this->ST = st;

    this->ST->reset_ST();
    // this->ST->print_ST();
    semantic_check(AST_root);
    print_errors();

}

void SemanticAnalysis::print_errors() {
    for (auto const& error : errors) {
        cout << error << endl;
    }
}

void SemanticAnalysis::semantic_check(Node* node) {
    string error;
    for (auto const& child : node->children) {
        semantic_check(child);
    }
    // error = node->report_semantic_error(ST->get_current_scope());
    error = node->report_semantic_error();
    // cout << error << endl;
    if (error != "") {
        this->errors.push_back(error);
    }
    // type checking, and scope adding
}
