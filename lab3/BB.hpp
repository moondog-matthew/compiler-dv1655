#ifndef BB_HPP
#define BB_HPP


#include "Tac.hpp"
#include "Node.h"


class BB {
private: 
    std::string name;
    std::vector<Tac*> tac_instructions;
    Tac* condition;
    BB* false_exit;
    BB* true_exit;
    int id;
    void generate_BB_content(int &count, ofstream *outStream);

public:
    BB();
    ~BB();

    string& getName();
    std::vector<Tac*>& getInstructions();
    Tac* getCondition();
    BB* getFalse();
    BB*  getTrue();
    void setFalse(BB* falseChild);
    void setTrue(BB* trueChild);
    void generate_BB();

};

#endif // BB_HPP