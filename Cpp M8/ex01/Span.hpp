# ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span {
    private:
        std::vector<int> v;
        unsigned int maxNumbers;
    public:
        Span();
        Span(unsigned int max_numbers);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        int shortestSpan();
        int longestSpan();
        void addNumber(int newNumber);

        class spanMaxError : public std::exception {
            virtual const char* what() const throw();
        };

        class spanError : public std::exception {
            virtual const char* what() const throw();
        };
};


# endif