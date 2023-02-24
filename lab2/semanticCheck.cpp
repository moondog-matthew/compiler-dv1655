#include "Node.h"
#include "symbolTable.cpp"

class SemanticAnalysis {
private:
    Node* AST_root;
    SymbolTable* ST; 
    vector<string> errors;
public:
    SemanticAnalysis(Node* ast, SymbolTable* st) {
        this->AST_root = ast;
        this->ST = st;

        this->ST->reset_ST();
        // this->ST->print_ST();
        semantic_check(AST_root);
        print_errors();

    }

    void print_errors() {
        for (auto const& error : errors) {
            cout << error << endl;
        }
    }

    void semantic_check(Node* node) {
        string error;
        for (auto const& child : node->children) {
            semantic_check(child);
        }
        error = node->report_semantic_error();
        // cout << error << endl;
        this->errors.push_back(error);
        // type checking, and scope adding
    }
};