#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const &oIntern);
        Intern &operator=(Intern const &oIntern);
        ~Intern();

        AForm* makeForm(std::string const &formName, std::string const &formtarget);
};

#endif