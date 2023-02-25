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

bool SemanticAnalysis::contains_error() const {
    if (errors.size() > 0) {
        return true;
    }
    return false;
}

void SemanticAnalysis::semantic_check(Node* node) {
    string error;
    for (auto const& child : node->children) {
        if(dynamic_cast<MainClassDeclaration*>(child) != nullptr) {
            ST->enter_scope();
            ST->enter_scope();
            semantic_check(child);
            ST->exit_scope();
            ST->exit_scope();
        }
        else if(dynamic_cast<ClassDeclaration*>(child) != nullptr) {
            ST->enter_scope();
            semantic_check(child);
            ST->exit_scope();
        }
        else if(dynamic_cast<Method*>(child) != nullptr) {
            ST->enter_scope();
            semantic_check(child);
            ST->exit_scope();
        }
        else {
            semantic_check(child);
        }
    }

    if (dynamic_cast<Identifier*>(node) != nullptr) { // check for usage of non-declared variables
        Identifier* iden = dynamic_cast<Identifier*>(node);
        string var = iden->getVal();
        if (ST->lookup_symbol(var) == nullptr) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Undefined variable " + var);
        }
    }
    
    error =  node->report_semantic_error();
    
    // cout << error << endl;
    if (error != "") {
        this->errors.push_back(error);
    }
    // type checking, and scope adding
}
