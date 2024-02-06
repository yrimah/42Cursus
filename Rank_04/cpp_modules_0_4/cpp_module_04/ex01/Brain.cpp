#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &oBrain)
{
    for (int i = 0; i < (sizeof(oBrain.ideas) / sizeof(int)); i++)
        this->ideas[i]  = oBrain.ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &oBrain)
{
    for (int i = 0; i < (sizeof(oBrain.ideas) / sizeof(int)); i++)
        this->ideas[i]  = oBrain.ideas[i];
    std::cout << "Brain assignment operator called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}