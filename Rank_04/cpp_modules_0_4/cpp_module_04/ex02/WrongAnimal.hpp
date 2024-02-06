#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const &oWrongAnimal);
        WrongAnimal &operator=(WrongAnimal const &oWrongAnimal);
        virtual ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;
};

#endif