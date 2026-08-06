#include "Tools.hpp"

bool infnanCheck(double value) {
    bool check = (value != value) || (value == std::numeric_limits<double>::infinity())
        || (value == -std::numeric_limits<double>::infinity());
    return (check);
}

void checkFloat(float value) {
    if (value != value)
        std::cout << "float: nanf" << std::endl;
    else if (value == std::numeric_limits<float>::infinity())
        std::cout << "float: inff" << std::endl;
    else if (value == -std::numeric_limits<float>::infinity())
        std::cout << "float: -inff" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
}

void checkDouble(double value) {
    if (value != value)
        std::cout << "double: nan" << std::endl;
    else if (value == std::numeric_limits<float>::infinity())
        std::cout << "double: inf" << std::endl;
    else if (value == -std::numeric_limits<float>::infinity())
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

bool outPut(long value) {
    if (value < 0 || value > 127 || !std::isprint(static_cast<int>(value)))
        std::cout << "char: " << (((value < 0) || (value > 127)) ? "impossible" : "Non displayable") << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) 
        << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    return true;
}

bool outPut(char value) {

    if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
        << static_cast<float>(value) << "f" << std::endl;    
    std::cout << "double: " << std::fixed << std::setprecision(1)
        << static_cast<double>(value) << std::endl;

    return true;
}

bool outPut(float value) {
    if (infnanCheck(value)){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else if (value < 0 || value > 127 || !std::isprint(static_cast<int>(value))) {
        std::cout << "char: " << (((value < 0) || (value > 127)) ? "impossible" : "Non displayable") << std::endl;
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
    checkFloat(value);
    if (value != value)
        std::cout << "double: nan" << std::endl;
    else if (value == std::numeric_limits<float>::infinity())
        std::cout << "double: inf" << std::endl;
    else if (value == -std::numeric_limits<float>::infinity())
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    return true;
}

bool outPut(double value) {
    if (infnanCheck(value)){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else if (value < 0 || value > 127 || !std::isprint(static_cast<int>(value))) {
        std::cout << "char: " << (((value < 0) || (value > 127)) ? "impossible" : "Non displayable") << std::endl;
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
    if (value != value)
        std::cout << "float: nanf" << std::endl;
    else if (value == std::numeric_limits<double>::infinity())
        std::cout << "float: inff" << std::endl;
    else if (value == -std::numeric_limits<double>::infinity())
        std::cout << "float: -inff" << std::endl;
    else if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" <<std::endl;     
    checkDouble(value);
    return true;
}