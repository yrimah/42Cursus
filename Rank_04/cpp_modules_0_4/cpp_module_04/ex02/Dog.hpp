#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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