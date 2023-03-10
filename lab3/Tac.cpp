#include "Tac.hpp"

Tac::Tac(string _op, string _lhs, string _rhs, string _result) : op(_op), lhs(_lhs), rhs(_rhs), result(_result) {}


ExprTac::ExprTac(string _op, string _lhs, string _rhs, string _result) : op(_op), lhs(_lhs), rhs(_rhs), result(_result) {}
string ExprTac::printTac() const {
    return result + " := " + lhs + " " + op + " " + rhs;
}

UnaryTac::UnaryTac(string _op, string _rhs, string _result) : op(_op), rhs(_rhs), result(_result) {}
string UnaryTac::printTac() const { 
    return result + " := " + op + " " + rhs;
}

CopyTac::CopyTac(string _lhs, string _result) : lhs(_lhs), result(_result) {}
string CopyTac::printTac() const {
    return result + " := " + lhs;
}

ArrAccTac::ArrAccTac(string _x, string _y, string _i) : x(_x), y(_y), i(_i) {}
string ArrAccTac::printTac() const {
    /* How do we handle ambiguity? Two different classs? */
    return x + " := " + y + "[" + i + "]";
    // return y + "[" + i + "] + " := " + x;
}

IndTac::IndTac(string _x, string _y, string _i) : x(_x), y(_y), i(_i) {}
string IndTac::printTac() const {
    return y + "[" + i + "]" + ":=" + x;
}

NewTac::NewTac(string _type, string _result) : result(_result), type(_type) {}
string NewTac::printTac() const {
    return result + " := new TYPE";
    // return result + " := new " + type;
}

NewArrTac::NewArrTac(string _size, string _result) : result(_result), size(_size) {}
string NewArrTac::printTac() const {
    return result + " := new TYPE, " + size;
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

ReturnTac::ReturnTac(string _retval) : retval(_retval) {}
string ReturnTac::printTac() const {
    return "return " + retval;
}

JumpTac::JumpTac(string _label) : label(_label) {}
string JumpTac::printTac() const {
    return "goto " + label;
}

CondTac::CondTac(string _x, string _label) : x(_x), label(_label) {}
string CondTac::printTac() const {
    return "iffalse " + x + " goto " + label;
}

PrintTac::PrintTac(string _expr) : expr(_expr) {}
string PrintTac::printTac() const {
    return "Print: " + expr;
}