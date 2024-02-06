#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
// # include "Character.hpp"

class Cure : public AMateria
{
    // private:

    public:
        Cure();
        Cure(Cure const &oCure);
        Cure &operator=(Cure const &oCure);
        ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);

};

#endif