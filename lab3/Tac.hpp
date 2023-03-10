#ifndef TAC_HPP
#define TAC_HPP
#include <string>
#include <iostream>

using namespace std;

class Tac {
private:
    string op, lhs, rhs, result;
public:
    Tac(string _op, string _lhs, string _rhs, string _result);
    Tac() = default;
    virtual ~Tac() = default;
    virtual string printTac() const = 0; // pure virtual
};

class ExprTac : public Tac {
public:
    string op, lhs, rhs, result;
    ExprTac(string _op, string _lhs, string _rhs, string _result);
    string printTac() const override;
};

class UnaryTac : public Tac {
public:
    string op, rhs, result;
    UnaryTac(string _op, string _rhs, string _result);
    string printTac() const override;
};

class CopyTac : public Tac {
public:
    string lhs, result;
    CopyTac(string _lhs, string _result);
    string printTac() const override;
};

class ArrAccTac : public Tac {
  public:
    string x; // singular val
    string y; // array 
    string i; // index
    ArrAccTac(string _x, string _y, string _i);
    string printTac() const override;
};

class IndTac : public Tac {
  public:
    string y; // array 
    string i; // index
    string x; // index value

    IndTac(string _x, string _y, string _i);
    string printTac() const override;
};

class NewTac : public Tac {
  public:
    string result;
    string type;
    NewTac(string _type, string _result);
    string printTac() const override;
};

class NewArrTac : public Tac {
  public:
    string result;
    string size;
    NewArrTac(string _size, string _result);
    string printTac() const override;
};

class LengthTac : public Tac {
public:
    string result;
    string y; // what to take length of
    LengthTac(string _y, string _result);
    string printTac() const override;
};

class ParTac : public Tac {
public:
    string param;
    ParTac(string _param);
    string printTac() const override;
};

class MethCallTac : public Tac {
public:
    string result;
    string func;
    string n_params;
    MethCallTac(string _func, string _n_params, string _result);
    
    string printTac() const override;
};

class ReturnTac : public Tac {
public:
    string retval;
    ReturnTac(string _retval);
    string printTac() const override;
};

class JumpTac : public Tac {
public:
    string label;
    JumpTac(string _label);
    string printTac() const override;
};

class CondTac : public Tac {
public:
    string x; // either true or false
    string label;
    CondTac(string _x, string _label);
    string printTac() const override;
};

class PrintTac : public Tac {
public:
    string expr;
    PrintTac(string _expr);
    string printTac() const override;
};

#endif // TAC_HPP