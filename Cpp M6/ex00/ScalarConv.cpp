#include "Tools.hpp"
#include "ScalarConv.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Scc Default Constructor Called..." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "Scc Copy Constructor Called..." << std::endl;
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "Scc Assisgnement Operator Called..." << std::endl;
    (void)other;

    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Scc Destructor Called..." << std::endl;
}

void ScalarConverter::convert(const std::string& lit) {
    int type = 0;
    if (lit.length() == 1 && !std::isdigit(lit[0])) {
        char value;
        char_handler(lit, value);
        outPut(value);
        return ;
    }
    type = variationsChecks(lit);
    int pseudo_type = handle_pseudos(lit); // No need for this one, since handle_pseaudo is called in variations checks by itself, worth a check for later
    if (pseudo_type != FAIL) {
        displayInfnan(pseudo_type);
    }
    else if (type == INT) {
        long value;
        if (!int_handler(lit, value) || !outPut(value))
            return ;
    }
    else if (type == FLOAT) {
        float value;
        if (!float_handler(lit, value) || !outPut(value))
            return ;
    }
    else if (type == DOUBLE) {
        double value;
        if (!double_handler(lit, value) || !outPut(value))
            return ;
    }
    else {
        std::cerr << "Unrecognized Format" << std::endl;
        return ;
    }
}