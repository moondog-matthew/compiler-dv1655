#ifndef CFG_HPP
#define CFG_HPP
#include "BB.hpp"
#include "Node.h"
#include "symbolTable.hpp"
#include <algorithm>

class CFG {
private: 
    BB* entry;
    vector<BB*> methods;
    std::map<string, string> BBnames;
    std::vector<string> printedBlocks;
    SymbolTable* ST;

    vector<BC*> bc;

public:
    CFG();
    CFG(Node* node, SymbolTable* _ST);
    void populate_CFG(Node* node);
    void generate_CFG();
    void generate_CFG_content(BB* block, int &count, ofstream *outStream);

    // Part 2 
    ProgramBC* generate_BC(); 
};


#endif // CFG_HPP