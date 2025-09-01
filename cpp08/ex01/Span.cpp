#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span::~Span() {}

Span &Span::operator=(const Span &assign)
{
    if (this != &assign)
	{
        _N = assign._N;
        _vec = assign._vec;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_vec.size() >= _N)
        throw std::length_error("Span is full");
    _vec.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
    if (std::distance(begin, end) + _vec.size() > _N)
        throw std::length_error("Span will be full");
    _vec.insert(_vec.end(), begin, end);
}

int Span::shortestSpan()
{
    if (_vec.size() <= 1)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());

    int min_span = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++)
	{
        if (sorted[i] - sorted[i-1] < min_span)
            min_span = sorted[i] - sorted[i-1];
    }
    return min_span;
}

int Span::longestSpan()
{
    if (_vec.size() <= 1)
        throw std::logic_error("Not enough numbers to find a span");

    return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}
