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
    if (op == "+") {
        instr = new InstructionBC(3, "iadd");
    }
    else if (op == "-") {
        instr = new InstructionBC(4, "isub");
    }
    else if (op == "*") {
        instr = new InstructionBC(5, "imul");
    }
    else if (op == "/") {
        instr = new InstructionBC(6, "idiv");
    }
    else if (op == ">") {
        instr = new InstructionBC(7, "igt");
    }
    else if (op == "<") {
        instr = new InstructionBC(8, "ilt");
    }
    else if (op == "==") {
        instr = new InstructionBC(9, "ieq");
    }
    else if (op == "||") {
        instr = new InstructionBC(10, "ior");
    }
    else if (op == "&&") {
        instr = new InstructionBC(11, "iand");
    }

}

UnaryTac::UnaryTac(string _op, string _rhs, string _result) : op(_op), rhs(_rhs), result(_result) {}
string UnaryTac::printTac() const { 
    return result + " := " + op + " " + rhs;
}
void UnaryTac::generate_code(vector<InstructionBC*> &bc) {
    
    InstructionBC* instr = new InstructionBC(12, "inot");

}

CopyTac::CopyTac(string _lhs, string _result) : lhs(_lhs), result(_result) {}
string CopyTac::printTac() const {
    return result + " := " + lhs;
}
void CopyTac::generate_code(vector<InstructionBC*> &bc) {
    
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

MethCallTac::MethCallTac(string _func, string _n_params, string _result) : func(_func), n_params(_n_params), result(_result) {}
string MethCallTac::printTac() const {
    return result + " := call " + func + ", " + n_params;  
}

void MethCallTac::generate_code(vector<InstructionBC*> &bc) {
    
}

ReturnTac::ReturnTac(string _retval) : retval(_retval) {}
string ReturnTac::printTac() const {
    return "return " + retval;
}
void ReturnTac::generate_code(vector<InstructionBC*> &bc) {
    
}

ExpressionTac::ExpressionTac(string _expr, string _result) : expr(_expr), result(_result) {}
string ExpressionTac::printTac() const {
    return result + " := " + expr;
}

JumpTac::JumpTac(string _label) : label(_label) {}
string JumpTac::printTac() const {
    return "goto " + label;
}
void JumpTac::generate_code(vector<InstructionBC*> &bc) {
    
}

CondTac::CondTac(string _x, string _label) : x(_x), label(_label) {}
string CondTac::printTac() const {
    return "iffalse " + x + " goto " + label;
}
void CondTac::generate_code(vector<InstructionBC*> &bc) {
    
}

PrintTac::PrintTac(string _expr) : expr(_expr) {}
string PrintTac::printTac() const {
    return "Print: " + expr;
}
void PrintTac::generate_code(vector<InstructionBC*> &bc) {

}