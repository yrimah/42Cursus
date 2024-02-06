#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
// # include <vector>
# include <deque>
# include <algorithm>
# include <list>

template<typename T, class Container = std::deque<T> > // We can use vector as another underlying container
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack()
        {}
        MutantStack(MutantStack const &oMutantStack)
        {
            *this = oMutantStack;
        }
        MutantStack &operator=(MutantStack const &oMutantStack)
        {
            this = oMutantStack;
            return (*this);
        }
        ~MutantStack()
        {}

        typedef typename Container::iterator iterator;

        iterator begin()
        {
            return (this->c.begin());
        }
        iterator end()
        {
            return (this->c.end());
        }
};

#endif