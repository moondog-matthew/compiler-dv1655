#include "Tac.hpp"

Tac::Tac(string _op, string _lhs, string _rhs, string _result) : op(_op), lhs(_lhs), rhs(_rhs), result(_result) {}
void Tac::generate_code(vector<InstructionBC*> &bc) {
    // Generate nothing. Not covered by assignment
}

ExprTac::ExprTac(string _op, string _lhs, string _rhs, string _result) : op(_op), lhs(_lhs), rhs(_rhs), result(_result) {}
string ExprTac::printTac() const {
    return result + " := " + lhs + " " + op + " " + rhs;
}
void ExprTac::generate_code(vector<InstructionBC*> &bc) {
    /* Different operators for same TAC */
    InstructionBC* instr; 
    instr = new InstructionBC(0, "iload " + lhs);
    bc.push_back(instr);
    instr = new InstructionBC(0, "iload " + rhs);
    bc.push_back(instr);
    if (op == "+") {
        instr = new InstructionBC(3, "iadd");
        bc.push_back(instr);
    }
    else if (op == "-") {
        instr = new InstructionBC(4, "isub");
        bc.push_back(instr);
    }
    else if (op == "*") {
        instr = new InstructionBC(5, "imul");
        bc.push_back(instr);
    }
    else if (op == "/") {
        instr = new InstructionBC(6, "idiv");
        bc.push_back(instr);
    }
    else if (op == ">") {
        instr = new InstructionBC(7, "igt");
        bc.push_back(instr);
    }
    else if (op == "<") {
        instr = new InstructionBC(8, "ilt");
        bc.push_back(instr);
    }
    else if (op == "==") {
        instr = new InstructionBC(9, "ieq");
        bc.push_back(instr);
    }
    else if (op == "||") {
        instr = new InstructionBC(10, "ior");
        bc.push_back(instr);
    }
    else if (op == "&&") {
        instr = new InstructionBC(11, "iand");
        bc.push_back(instr);
    }
    instr = new InstructionBC(2, "istore " + result);
    bc.push_back(instr);
}

UnaryTac::UnaryTac(string _op, string _rhs, string _result) : op(_op), rhs(_rhs), result(_result) {}
string UnaryTac::printTac() const { 
    return result + " := " + op + " " + rhs;
}
void UnaryTac::generate_code(vector<InstructionBC*> &bc) {
    InstructionBC* instr;
    instr = new InstructionBC(0, "iload " + rhs);
    bc.push_back(instr);
    instr = new InstructionBC(12, "inot");
    bc.push_back(instr);
    instr = new InstructionBC(2 , "iload " + rhs);
    bc.push_back(instr);
}

CopyTac::CopyTac(string _rhs, string _result) : rhs(_rhs), result(_result) {}
string CopyTac::printTac() const {
    return result + " := " + rhs;
}
void CopyTac::generate_code(vector<InstructionBC*> &bc) {
    InstructionBC* instr;
    instr = new InstructionBC(0, "iload " + rhs);
    bc.push_back(instr);
    instr = new InstructionBC(2 , "istore " + result);
    bc.push_back(instr);
}

IndexTac::IndexTac(string _result, string _y, string _i) : result(_result), y(_y), i(_i) {}
string IndexTac::printTac() const {
    return result + " =: " + y + "[" + i + "]";
}

ArrAccTac::ArrAccTac(string _z, string _y, string _i) : z(_z), y(_y), i(_i) {}
string ArrAccTac::printTac() const {
    /* How do we handle ambiguity? Two different classs? */
    return z + " := " + y + "[" + i + "]";
}

NewIdenTac::NewIdenTac(string _type, string _result) : result(_result), type(_type) {}
string NewIdenTac::printTac() const {
    return result + " := new " + type;
    // return result + " := new " + type;
}

NewArrTac::NewArrTac(string _size, string _type,string _result) : result(_result), type(_type) ,size(_size) {}
string NewArrTac::printTac() const {
    return result + " := new " + type + "," + size;
}

LengthTac::LengthTac(string _y, string _result) : y(_y), result(_result) {}
string LengthTac::printTac() const {
    return result + " := length " + y;  
}

ParTac::ParTac(string _param) : param(_param) {}
string ParTac::printTac() const {
    return "param " + param; 
}
void ParTac::generate_code(vector<InstructionBC*> &bc) {
    // pop argument from stack
    // place value in param
}

MethCallTac::MethCallTac(string _func, string _n_params, string _result) : func(_func), n_params(_n_params), result(_result) {}
string MethCallTac::printTac() const {
    return result + " := call " + func + ", " + n_params;  
}

void MethCallTac::generate_code(vector<InstructionBC*> &bc) {
    /* WRITE HERE */
    // Push N arguments to the stack
    // which ones?
    // Invokevirtual m

}

ReturnTac::ReturnTac(string _retval) : retval(_retval) {}
string ReturnTac::printTac() const {
    return "return " + retval;
}
void ReturnTac::generate_code(vector<InstructionBC*> &bc) {
    InstructionBC* instr;
    instr = new InstructionBC(0, "iload " + this->retval);
    bc.push_back(instr);
    instr = new InstructionBC(16, "ireturn");
    bc.push_back(instr);
}

ExpressionTac::ExpressionTac(string _expr, string _result) : expr(_expr), result(_result) {}
string ExpressionTac::printTac() const {
    return "Argument: " + result + " := " + expr;
}

JumpTac::JumpTac(string _label) : label(_label) {}
string JumpTac::printTac() const {
    return "goto " + label;
}
void JumpTac::generate_code(vector<InstructionBC*> &bc) {
    InstructionBC* instr;
    instr = new InstructionBC(13, "goto " + label);
    bc.push_back(instr);
}

CondTac::CondTac(string _x, string _label) : x(_x), label(_label) {}
string CondTac::printTac() const {
    return "iffalse " + x + " goto " + label;
}
void CondTac::generate_code(vector<InstructionBC*> &bc) {
    InstructionBC* instr;
    instr = new InstructionBC(0, "iload " + x);
    bc.push_back(instr);
    instr = new InstructionBC(14, "iffalse goto " + label);
    bc.push_back(instr);
}

PrintTac::PrintTac(string _expr) : expr(_expr) {}
string PrintTac::printTac() const {
    return "Print: " + expr;
}
void PrintTac::generate_code(vector<InstructionBC*> &bc) {
    InstructionBC* instr;
    instr = new InstructionBC(0, "iload " + expr);
    bc.push_back(instr);
    instr = new InstructionBC(17 , "print");
    bc.push_back(instr);
}

LabelTac::LabelTac(string _label) : label(_label) {}
string LabelTac::printTac() const {
    return label + ":";
}
void LabelTac::generate_code(vector<InstructionBC*> &bc) {
    InstructionBC* instr;
    instr = new InstructionBC(19, label + ":");
    bc.push_back(instr);
}
