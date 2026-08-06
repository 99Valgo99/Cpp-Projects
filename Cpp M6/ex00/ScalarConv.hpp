# ifndef SCALARCONV_HPP
# define SCALARCONV_HPP

# include <iostream>
# include <cctype>
# include <limits>
# include <cstdlib>
# include <cerrno>
# include <string>

# define FAIL 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define SUCCESS 4
# define CHAR 8

# define NAN 5
# define INF 6
# define NINF 7

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        static void convert(const std::string& lit);
};

# endif