# ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>
# include <iterator>
# include <list>
# include <ctime>

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

        unsigned int maxNumbersGetter() const;

        class spanMaxError : public std::exception {
            virtual const char* what() const throw();
        };

        class spanError : public std::exception {
            virtual const char* what() const throw();
        };

        template <typename Iter> void addRangedNumber(Iter one, Iter two) {
            if (v.size() + std::distance(one, two) > maxNumbers) {
                throw spanMaxError();
            }
            std::copy(one, two, std::back_inserter(v));
        }
};


# endif