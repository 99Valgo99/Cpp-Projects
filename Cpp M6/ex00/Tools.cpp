#include "Tools.hpp"

int handle_pseudos(const std::string& lit) {
    if (!lit.compare("nan") || !lit.compare("nanf"))
        return (NAN); 
    else if (!lit.compare("inf") || !lit.compare("+inf")
    || !lit.compare("inff") || !lit.compare("+inff"))
        return (INF);
    else if (!lit.compare("-inf") || !lit.compare("-inff"))
        return (NINF);
    return (FAIL);
}

int variationsChecks(const std::string& lit) {
    
    int x = 0;
    int y = 0;
    int z = 0;
    bool has_dot = false;

    for (unsigned long i = 0; i < lit.length(); i++) {
        if (lit[i] == '.')
            has_dot = true;
    }
    for (unsigned long i = 0; i < lit.length(); i++) {
        if (lit[i] == '-' || lit[i] == '+')
            x++;
        if (lit[i] == '.') {
            if (lit[i + 1] && !std::isdigit(lit[i + 1]))
                return FAIL;
            y++;
        }
        if (std::isdigit(lit[i]))
            z++;
        if (!std::isprint(lit[i]) || x >= 2 || y >= 2 || lit[0] == '.'
                || lit[lit.length() - 1] == '.')
            return FAIL;
        if (std::isdigit(lit[i]) && y == 1 && lit[lit.length() - 1] != 'f')
           return (DOUBLE);
        if (z >= 2 && y == 1 && lit[lit.length() - 1] == 'f')
            return (FLOAT);
        if (y == 0 && z >= 1 && has_dot == false)
            return (INT);
    }
    return (handle_pseudos(lit));
}

bool double_handler(const std::string& lit, double& result) {
   
    errno = 0;
    char *endchar = 0;

    double res = std::strtod(lit.c_str(), &endchar);    
    if (*endchar != '\0') {
        std::cerr << "Unrecongnized Format, From Method Handler. (Double)" << std::endl;
        return false;
    }
    if (errno == ERANGE) {
        std::cerr << "Value is Larger/Smaller to fit into a Double." << std::endl;
        return false;
    }
    result = res;
    return true;
}

bool float_handler(const std::string& lit, float& result) {

    errno = 0;
    char *endchar = 0;
    std::string floated = lit;

    if (lit[lit.size()-1] == 'f')
        floated.resize(lit.size() - 1);
    double cast_float = std::strtod(floated.c_str(), &endchar);
    if (*endchar != '\0') {
        std::cerr << "Unrecongnized Format, From Method Handler. (Float)" << std::endl;
        return false;
    }
    if (errno == ERANGE) {
        std::cerr << "Value is Larger/Smaller to fit into a Double." << std::endl;
        return false;
    }
    float res = static_cast<float>(cast_float);
    result = res;
    return true;
}

bool char_handler(const std::string& lit, char& result) {
    result = lit[0];
    return true;
}

bool int_handler(const std::string& lit, long& result) {
    
    errno = 0;
    char *endchar = 0;

    long integer = std::strtol(lit.c_str(), &endchar, 10);
    if (*endchar != '\0') {
        std::cerr << "Unrecognized Format, From Method Handler. (Int)" << std::endl;
        return false;
    }
    if (errno == ERANGE) {
        std::cerr << "Value is Larger/Smaller to fit into a Long." << std::endl;
        return false;
    }
    if ((integer > std::numeric_limits<int>::max() )
        | (integer < std::numeric_limits<int>::min())) {
        std::cerr << "Value is Larger/Smaller to fit into a Int" << std::endl;
        return false;
    }
    result = integer;
    return true;
}


