#ifndef TAC_HPP
#define TAC_HPP
#include <string>
#include <iostream>

using namespace std;

class Tac {
protected:
    string op, lhs, rhs, result;
public:
    Tac(string _op, string _lhs, string _rhs, string _result);
    virtual ~Tac() = default;
    virtual string getOperator();
    virtual string getLHS();
    virtual string getRHS();
    virtual string getResult();
    virtual string printTac();
};

class ExprTac : public Tac {
public:
    ExprTac(string _op, string _lhs, string _rhs, string _result);
};

class MethTac : public Tac {
public:
    MethTac(string _op, string _lhs, string _rhs, string _result);
};

class JumpTac : public Tac {
public:
    JumpTac(string _op, string _lhs, string _rhs, string _result);
};

class CondTac : public Tac {
public:
    CondTac(string _op, string _lhs, string _rhs, string _result);
};

#endif // TAC_HPP