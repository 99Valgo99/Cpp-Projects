# ifndef TOOLS_HPP
# define TOOLS_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include <limits>
# include <cstdlib>
# include <cerrno>
# include <string>

# include "ScalarConv.hpp"

int     variationsChecks(const std::string& lit);

int     handle_pseudos(const std::string& lit);
bool    int_handler(const std::string& lit, long& result);
bool    char_handler(const std::string& lit, char& result);
bool    float_handler(const std::string& lit, float& result);
bool    double_handler(const std::string& lit, double& result);

bool    outPut(char value);
bool    outPut(long value);
bool    outPut(float value);
bool    outPut(double value);

bool    displayInfnan(int pseudo_type);


# endif