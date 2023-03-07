#include "BB.hpp"
#include <iostream>

int main() {
    ExprTac* first = new ExprTac("Oper", "lhs", "rhs", "Res");
    BB* test = new BB();
    test->add_Tac(first);
    BB* t1 = new BB();
    BB* f1 = new BB();

    t1->add_Tac(new ExprTac("hej", "på", "dig", "Marcus"));
    f1->add_Tac(new ExprTac("Nej", "jag", "heter", "Jol"));

    test->setTrue(t1);
    test->setFalse(f1);

    test->generate_BB();

}