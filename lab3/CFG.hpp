#ifndef CFG_HPP
#define CFG_HPP
#include "BB.hpp"
#include "Node.h"

class CFG {
private: 
    BB* entry;
    vector<BB*> methods;
    std::map<string, string> BBnames;

public:
    CFG();
    CFG(Node* node);
    void populate_CFG(Node* node);
    void generate_CFG();
    void generate_CFG_content(BB* block, int &count, ofstream *outStream);

};


#endif // CFG_HPP