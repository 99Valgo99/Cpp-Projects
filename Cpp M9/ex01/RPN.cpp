# include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    (void)other;
}

RPN& RPN::operator=(const RPN& other) {
    (void)other;
    return *this;
}

RPN::~RPN() {}

bool RPN::expressionNature(const std::string& exp) {
    for (size_t i = 0; i < exp.size(); i++) {
        if (!std::isdigit(exp[i]) && exp[i] != '+' && exp[i] != '-'
            && exp[i] != '*' && exp[i] != '/' && exp[i] != ' '
                && exp[i] != '\t')
            return false;
    }
    return true;
}

bool RPN::operatorNature(const char& exp) {
    if (exp == '-' || exp == '+' || exp == '*'
        || exp == '/')
        return true;
    return false;
}

double RPN::convertReturn(const std::string& exp) {
    return (std::strtod(exp.c_str(), NULL));
}

double RPN::applyOps(double x, double y, const char& exp) {
    if (exp == '-')
        return (x - y);
    else if (exp == '+')
        return (x + y);
    else if (exp == '*')
        return (x * y);
    return (x / y);
}