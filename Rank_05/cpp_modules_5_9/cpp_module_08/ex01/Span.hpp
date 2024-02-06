#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <cmath>

class Span
{
    private:
        unsigned int N;
        std::list<int> span;
    
    public:
        Span();
        Span(unsigned int N);
        Span(Span const &oSpan);
        Span &operator=(Span const &oSpan);
        ~Span();

        void addNumber(int number);

        int shortestSpan(void) const;
        int longestSpan(void) const;

        void addNumber(std::list<int>::iterator span_it_begin, std::list<int>::iterator span_it_end);

        const std::list<int> &getSpan(void) const;

        class FullSpanException : public std::exception
        {
            public:
                virtual const char * what() const throw()
                {
                    return ("The span is full, can't add more numbers!");
                }
        };

        class NoSpanFound : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("No span can be found!");
                }
        };
};

std::ostream& operator<<(std::ostream&, const Span&);

#endif