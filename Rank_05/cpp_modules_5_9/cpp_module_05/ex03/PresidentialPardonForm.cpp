#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm()
// {
//     std::cout << "PresidentialPardonForm default constructor called." << std::endl;
// }

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm parametrized constructor called." << std::endl;
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &oPresidentialPardonForm) : AForm(oPresidentialPardonForm)
{
    std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
    this->target = oPresidentialPardonForm.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &oPresidentialPardonForm)
{
    this->target = oPresidentialPardonForm.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getAFormStatus())
        throw AForm::FormNotSigned();
    if (this->getExecGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();

    std::cout << "[ " << this->target << " ] : " << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called." << std::endl;
}