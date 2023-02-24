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

        cout << "Test 1" << endl;
        this->ST->reset_ST();
        // this->ST->print_ST();
        cout << "Test 2" << endl;
        semantic_check(AST_root);

    }

    void print_errors() {
        for (auto const& error : errors) {
            cout << error << endl;
        }
    }

    void semantic_check(Node* node) {
        string error;
        cout << "Test 3" << endl;
        for (auto const& child : node->children) {
            semantic_check(child);
        }
        cout << "Test Post" << endl;
        error = node->report_semantic_error();
        cout << error << endl;
        // type checking, and scope adding
    }
};