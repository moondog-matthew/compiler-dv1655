#ifndef TAC_HPP
#define TAC_HPP
#include <string>
#include <iostream>
#include "BC.hpp"

using namespace std;

class Tac {
private:
    string op, lhs, rhs, result;
public:
    Tac(string _op, string _lhs, string _rhs, string _result);
    Tac() = default;
    virtual ~Tac() = default;
    virtual string printTac() const = 0; // pure virtual
    virtual void generate_code(vector<InstructionBC*> &bc);
};

class ExprTac : public Tac {
public:
    string op, lhs, rhs, result;
    ExprTac(string _op, string _lhs, string _rhs, string _result);
    string printTac() const override;
    void generate_code(vector<InstructionBC*> &bc) override;
};

class UnaryTac : public Tac {
public:
    string op, rhs, result;
    UnaryTac(string _op, string _rhs, string _result);
    string printTac() const override;
    void generate_code(vector<InstructionBC*> &bc) override;
};

class CopyTac : public Tac {
public:
    string lhs, result;
    CopyTac(string _lhs, string _result);
    string printTac() const override;
    void generate_code(vector<InstructionBC*> &bc) override;

};

class IndexTac : public Tac {
public:
    string result;
    // y[i]
    string y;
    string i;
    IndexTac(string result, string _y, string _i);
    string printTac() const override;
};

class ArrAccTac : public Tac {
  public:
    // y[i] = z;
    string y; // array 
    string i; // index
    string z; // singular val
    ArrAccTac(string _y, string _i, string _z);
    string printTac() const override;
};

class NewIdenTac : public Tac {
  public:
	/*new IDEN()*/
    string result;
    string type;
    NewIdenTac(string _type, string _result);
    string printTac() const override;
};

class NewArrTac : public Tac {
  public:
  	/* new int[i]*/
    string result;
    string size;
    string type;
    NewArrTac(string _size, string _type, string _result);
    string printTac() const override;
};

class LengthTac : public Tac {
public:
    string result;
    string y; // what to take length of
    LengthTac(string _y, string _result);
    string printTac() const override;
};

class PrintTac : public Tac {
public:
    string expr;
    PrintTac(string _expr);
    string printTac() const override;
    void generate_code(vector<InstructionBC*> &bc) override;

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
    void generate_code(vector<InstructionBC*> &bc) override;

};

class ReturnTac : public Tac {
public:
    string retval;
    ReturnTac(string _retval);
    string printTac() const override;
    void generate_code(vector<InstructionBC*> &bc) override;
};

class ExpressionTac : public Tac {
public:
    /* (Expression)*/
    string expr;
    string result;
    ExpressionTac(string _expr, string _result);
    string printTac() const override;
};

class JumpTac : public Tac {
public:
    string label;
    JumpTac(string _label);
    string printTac() const override;
    void generate_code(vector<InstructionBC*> &bc) override;
};

class CondTac : public Tac {
public:
    string x; // condition
    string label;
    CondTac(string _x, string _label);
    string printTac() const override;
    void generate_code(vector<InstructionBC*> &bc) override;

};



#endif // TAC_HPP