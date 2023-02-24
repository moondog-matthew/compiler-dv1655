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

    }

    void print_errors() {
        for (auto const& error : errors) {
            cout << error << endl;
        }
    }

    void semantic_check() {
        int sz = AST_root->children.size();
        for (int i = 0; i < sz; ++i) {

        }
        cout << sz << endl;
    }
};