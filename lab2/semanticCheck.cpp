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
        if(dynamic_cast<MainClassDeclaration*>(node) != nullptr) {
            ST->enter_scope();
            semantic_check(child);
            ST->exit_scope();
        }
        else if(dynamic_cast<ClassDeclaration*>(node) != nullptr) {
            ST->enter_scope();
            semantic_check(child);
            ST->exit_scope();
        }
        else if(dynamic_cast<Method*>(node) != nullptr) {
            ST->enter_scope();
            semantic_check(child);
            ST->exit_scope();
        }
        else {
            semantic_check(child);
        }
    }
    
    if (dynamic_cast<IntVal*>(node) != nullptr) {
        // IntVal* intval = dynamic_cast<IntVal*>(node);
        // string ret = intval->getVal();
    }
    else if (dynamic_cast<Identifier*>(node) != nullptr) {
        // Identifier* identifier = dynamic_cast<Identifier*>(node);
        // string ret = identifier->getVal();
        // cout << ret << endl;
    }
    else if (dynamic_cast<Identifier*>(node) != nullptr) {
        // Identifier* identifier = dynamic_cast<Identifier*>(node);
        // string ret = identifier->getVal();
        // cout << ret << endl;
    }
    else if (dynamic_cast<Variable*>(node) != nullptr) {
        Variable* var = dynamic_cast<Variable*>(node);
        string type = var->getType();
        string iden = var->getIden();

        // cout <<  type << " " << iden << endl;
    }

    // string name = "tst";
    // Record* res = ST->lookup_symbol(name);
    // if (res == nullptr) {
    //     errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Undefined variable " + name);
    // }

    error = node->report_semantic_error();

    // cout << error << endl;
    if (error != "") {
        // this->errors.push_back(error);
    }
    // type checking, and scope adding
}
