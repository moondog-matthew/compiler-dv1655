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

string SemanticAnalysis::semantic_check(Node* node) {
    string error;
    if(dynamic_cast<MainClassDeclaration*>(node) != nullptr) {
        ST->enter_scope();
        ST->enter_scope();
        string ret = semantic_check(node);
        ST->exit_scope();
        ST->exit_scope();
        return "void"; // hard coded
    }
    else if(dynamic_cast<ClassDeclaration*>(node) != nullptr) {
        ClassDeclaration* type = dynamic_cast<ClassDeclaration*>(node);
        ST->enter_scope();
        for (auto const& child : node->children) {
            semantic_check(node);
        }
        ST->exit_scope();
        return type->getIden();
    }
    else if(dynamic_cast<Method*>(node) != nullptr) {
        Method* type = dynamic_cast<Method*>(node);
        for (auto const& child : node->children) {
            ST->enter_scope();
            string ret = semantic_check(node);
            ST->exit_scope();
        }
        auto ret_type = node->children.back()->type; // auto gets the arbitrary type
        if (ret_type != type->getType()) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Type mismatch: Return value type (type"+ret_type +") and method type (type"+type->getType() +")is not alligning.");
        }
        return type->getType();
    }
    else if (dynamic_cast<Identifier*>(node) != nullptr) { // check for usage of non-declared variables
        Identifier* iden = dynamic_cast<Identifier*>(node);
        string var = iden->getVal();
        if (ST->lookup_symbol(var) == nullptr) {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Undefined variable " + var);
        }
        return iden->type;
    }
    else if (dynamic_cast<IntVal*>(node) != nullptr) {
        return "int";
    }
    else if (node->type == "AddExpression" || node->type == "SubExpression" || node->type == "MultExpression" || node->type == "DivExpression") { 
        string LHS = semantic_check(node->children[0]);
        string RHS = semantic_check(node->children[1]);
        if (LHS != "int" || RHS != "int") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Expression '" + node->type + "' is not supported between types" + LHS + "" + RHS);
        }
        
        return "int";
    }
    else if (node->type == "GreaterThan" || node->type == "LessThan") { // GT and LT
        string LHS = semantic_check(node->children[0]);
        string RHS = semantic_check(node->children[1]);
        if (LHS != "int" || RHS != "int") {
            errors.push_back("@error at line: " + to_string(node->lineno) + ". Semantic Error: Expression '" + node->type + "' is not supported between types" + LHS + "" + RHS);
        } 
        return "bool";
    }
    else 



    // error =  node->report_semantic_error();
    
    // cout << error << endl;
    // if (error != "") {
    //     this->errors.push_back(error);
    // }
    // type checking, and scope adding
}
