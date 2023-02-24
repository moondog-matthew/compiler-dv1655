#include "Node.h"
#include "symbolTable.cpp"

class SemanticAnalysis {
private:
    Node* AST;
    SymbolTable* ST; 
    vector<string> errors;
public:
    SemanticAnalysis(Node* ast, SymbolTable* st) {
        this->AST = ast;
        this->ST = st;
    }

    void print_errors() {
        for (auto const& error : errors) {
            cout << error << endl;
        }
    }

    void semantic_check() {
        int sz = AST->children.size();
        for (int i = 0; i < sz; ++i) {

        }
        cout << sz << endl;
    }
};