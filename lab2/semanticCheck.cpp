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
    if(dynamic_cast<MainClassDeclaration*>(node) != nullptr) {
        ST->enter_scope();
        string name = "tst";
        Record* res = ST->lookup_symbol(name);
        if (res == nullptr) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Undefined variable " + name);
        }
    }
    else if(dynamic_cast<ClassDeclaration*>(node) != nullptr) {
        ST->enter_scope();
    }
    else if(dynamic_cast<Method*>(node) != nullptr) {
        ST->enter_scope();
    }
    
    // error = node->report_semantic_error();
    // cout << error << endl;
    if (error != "") {
        // this->errors.push_back(error);
    }
    // type checking, and scope adding
}
