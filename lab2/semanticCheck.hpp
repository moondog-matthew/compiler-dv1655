#ifndef SEMANTIC_H
#define	SEMANTIC_H


#include "Node.h"
#include "symbolTable.hpp"
using namespace std;

class SemanticAnalysis {
private:
    Node* AST_root;
    SymbolTable* ST; 
    vector<string> errors;

public:
    SemanticAnalysis(Node* ast, SymbolTable* st);
    void print_errors();
    bool contains_error() const;
    void semantic_check(Node* node);
    
};

#endif // SEMANTIC_H