#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack() : std::stack<T, Container>() {}
        MutantStack(const MutantStack<T, Container>& copy) : std::stack<T, Container>(copy) {}
        MutantStack<T, Container>& operator=(const MutantStack<T, Container>& assign)
		{
            if (this != &assign)
                this->c = assign.c;
            return *this;
        }
        ~MutantStack() {}

        typedef typename Container::iterator iterator;

        iterator begin()
		{
            return this->c.begin();
        }
		
        iterator end()
		{
            return this->c.end();
        }
};

#endif
