#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain* oBrain;
    public:
        Cat();
        Cat(Cat const &oCat);
        Cat &operator=(Cat const &oCat);
        ~Cat();

        std::string getType() const;
        void makeSound() const;
};

#endif