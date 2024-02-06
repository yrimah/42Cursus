#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->materia[i] = 0;
    std::cout << "MateriaSource constructor called." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &oMateriaSource)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materia[i])
            this->materia[i] = 0;
        if (oMateriaSource.materia[i])
            this->materia[i] = oMateriaSource.materia[i];
    }
    std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &oMateriaSource)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materia[i])
            delete this->materia[i];
        if (oMateriaSource.materia[i])
            this->materia[i] = oMateriaSource.materia[i];
    }
    std::cout << "MateriaSource assignment operator called." << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materia[i])
            delete this->materia[i];
    }
    std::cout << "MateriaSource destructor called." << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!materia[i])
        {
            materia[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i] && materia[i]->getType() == type)
            return (materia[i]->clone());
    }
    return (NULL);
}