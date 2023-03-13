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

public:
    CFG();
    CFG(Node* node, SymbolTable* _ST);
    void populate_CFG(Node* node);
    void generate_CFG();
    void generate_CFG_content(BB* block, int &count, ofstream *outStream);
    const vector<BB*>& getMethods() const;

    // Part 2 
    ProgramBC* generate_BC(); 
    void method_bc_content(BB* bb, vector<InstructionBC*> &instructions);
};


#endif // CFG_HPP