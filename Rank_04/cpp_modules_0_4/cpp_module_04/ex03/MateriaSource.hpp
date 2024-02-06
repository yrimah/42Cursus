#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* materia[4];

    public:
        MateriaSource();
        MateriaSource(MateriaSource const &oMateriaSource);
        MateriaSource &operator=(MateriaSource const &oMateriaSource);
        ~MateriaSource();

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif