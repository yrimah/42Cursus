#include "AForm.hpp"

// AForm::AForm()
// {
//     std::cout << "AForm default constructor called." << std::endl;
// }

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
    std::cout << "AForm parametrized constructor called." << std::endl;
    this->AFormStatus = false;
    try
    {
        if (signGrade < 1 || execGrade < 1)
            throw AForm::GradeTooHighException();
        if (signGrade > 150 || execGrade > 150)
            throw AForm::GradeTooLowException();
            std::cout << "AForm grades applied." << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "[ Exception ] : " << e.what() << std::endl;
    }
}

AForm::AForm(AForm const &oAForm) : name(oAForm.name), signGrade(oAForm.signGrade), execGrade(oAForm.execGrade)
{
    std::cout << "AForm copy constructor called." << std::endl;
}

AForm &AForm::operator=(AForm const &oAForm)
{
    std::cout << "AForm copy assignment operator called." << std::endl;
    this->AFormStatus = oAForm.AFormStatus;
    return (*this);
}

std::string const AForm::getName() const
{
    return (this->name);
}

bool const AForm::getAFormStatus() const
{
    return (this->AFormStatus);
}

int const AForm::getSignGrade() const
{
    return (this->signGrade);
}

int const AForm::getExecGrade() const
{
    return (this->execGrade);
}

void AForm::beSigned(Bureaucrat const &oBureaucrat)
{
    if (oBureaucrat.getGrade() <= this->getSignGrade())
        this->AFormStatus = true;
    else
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
    std::cout << "AForm destructor called." << std::endl;
}

std::ostream &operator<<(std::ostream &o, AForm const &oAForm)
{
    o << "[ " << oAForm.getName() << " | " << int(oAForm.getAFormStatus()) << " | " << oAForm.getSignGrade() << " | " << oAForm.getExecGrade() ;
    return (o);
}

