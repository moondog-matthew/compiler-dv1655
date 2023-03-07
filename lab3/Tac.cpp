#include "Tac.hpp"

Tac::Tac(string _op, string _lhs, string _rhs, string _result) : op(_op), lhs(_lhs), rhs(_rhs), result(_result) {}

string Tac::getOperator() {
    return this->op;
}

string Tac::getLHS() {
    return this->lhs;
}

string Tac::getRHS() {
    return this->rhs;
}

string Tac::getResult() {
    return this->result;
}

string Tac::printTac() {
    return result + " := " + lhs + " " + op + " " + rhs; 
}

ExprTac::ExprTac(string _op, string _lhs, string _rhs, string _result) : Tac(_op, _lhs, _rhs, _result) {}

MethTac::MethTac(string _op, string _lhs, string _rhs, string _result) : Tac(_op, _lhs, _rhs, _result) {}

JumpTac::JumpTac(string _op, string _lhs, string _rhs, string _result) : Tac(_op, _lhs, _rhs, _result) {}

CondTac::CondTac(string _op, string _lhs, string _rhs, string _result) : Tac(_op, _lhs, _rhs, _result) {}