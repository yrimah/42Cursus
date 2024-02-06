#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "Character.hpp"
# include "AMateria.hpp"

class Ice : public AMateria
{
    // private:

    public:
        Ice();
        Ice(Ice const &oIce);
        Ice &operator=(Ice const &Ice);
        ~Ice();

        AMateria* clone() const;
        void use(ICharacter& target);

};

#endif