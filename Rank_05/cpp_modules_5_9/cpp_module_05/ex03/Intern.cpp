#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(Intern const &oIntern)
{
    std::cout << "Intern copy constructor called." << std::endl;
}

Intern &Intern::operator=(Intern const &oIntern)
{
    std::cout << "Intern copy assignment operator called." << std::endl;
    *this = oIntern;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called." << std::endl;
}

AForm* Intern::makeForm(std::string const &formName, std::string const &formtarget)
{
    std::string formNames[] = {"robotomy request", "Shrubbery creation", "Presidential pardon"};
    AForm* Forms[] = {new RobotomyRequestForm(formtarget), new ShrubberyCreationForm(formtarget), new PresidentialPardonForm(formtarget)};

    for (int i = 0; i < 3; i++)
    {
        if (!formName.compare(formNames[i]))
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (Forms[i]);
        }
    }
    // throw AForm::unexistForm();
    std::cout <<  formName << "Form doesn't exist " << std::endl;
    return (NULL);
}