#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const &oWrongCat);
        WrongCat &operator=(WrongCat const &oWrongCat);
        ~WrongCat();

        std::string getType() const;
        void makeSound() const;
};

#endif