#include "BB.hpp"
#include <iostream>

int main() {
    MethTac* first = new MethTac("Oper", "lhs", "rhs", "Res");
    BB* test = new BB();
    test->generate_BB();
}