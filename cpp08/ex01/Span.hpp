#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        std::vector<int> _vec;
        unsigned int _N;
        Span();

    public:
        Span(unsigned int N);
        Span(const Span &copy);
        ~Span();
        Span &operator=(const Span &assign);

        void addNumber(int number);
        void addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
        int shortestSpan();
        int longestSpan();
};

#endif
