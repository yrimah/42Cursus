#ifndef CHARACTER_HPP
# define CHARACTER_HPP

// # include <iostream>
// # include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *slot[4];

    public:
        Character();
        Character(std::string name);
        Character(Character const &oCharacter);
        Character &operator=(Character const &oCharacter);
        ~Character();

        std::string const &getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        AMateria* getMateria(int idx);
};

#endif