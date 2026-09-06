# ifndef RPN_HPP
# define RPN_HPP

# include <cctype>
# include <cstdlib>
# include <cmath>
# include <stack>
# include <sstream>
# include <iostream>

class RPN {
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        static bool expressionNature(const std::string& exp);
        static bool operatorNature(const char& exp);
        static double convertReturn(const std::string& exp);
        static double applyOps(double x, double y, const char& exp);
};

#endif