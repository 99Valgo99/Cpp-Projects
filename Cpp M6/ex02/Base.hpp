# ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <iostream>
# include <ctime>

class Base {
    public:
        virtual ~Base();
        private:
};
    
Base* generate();
void identify(Base* p);
void identify(Base& p);

# endif