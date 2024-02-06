#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* oBrain;
    public:
        Dog();
        Dog(Dog const &oDog);
        Dog &operator=(Dog const &oDog);
        ~Dog();

        std::string getType() const;
        void makeSound() const;
        
};

#endif