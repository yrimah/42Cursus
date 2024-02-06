#include "Form.hpp"

// Form::Form()
// {
//     std::cout << "Form default constructor called." << std::endl;
// }

Form::Form(const std::string name, const int signGrade, const int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
    std::cout << "Form parametrized constructor called." << std::endl;
    this->formStatus = false;
    try
    {
        if (signGrade < 1 || execGrade < 1)
            throw Form::GradeTooHighException();
        if (signGrade > 150 || execGrade > 150)
            throw Form::GradeTooLowException();
            std::cout << "Form grades applied." << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "[ Exception ] : " << e.what() << std::endl;
    }
}

Form::Form(Form const &oForm) : name(oForm.name), signGrade(oForm.signGrade), execGrade(oForm.execGrade)
{
    std::cout << "Form copy constructor called." << std::endl;
}

Form &Form::operator=(Form const &oForm)
{
    std::cout << "Form copy assignment operator called." << std::endl;
    this->formStatus = oForm.formStatus;
    return (*this);
}

std::string const Form::getName() const
{
    return (this->name);
}

bool const Form::getFormStatus() const
{
    return (this->formStatus);
}

int const Form::getSignGrade() const
{
    return (this->signGrade);
}

int const Form::getExecGrade() const
{
    return (this->execGrade);
}

void Form::beSigned(Bureaucrat const &oBureaucrat)
{
    if (oBureaucrat.getGrade() <= this->getSignGrade())
        this->formStatus = true;
    else
        throw Form::GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Form destructor called." << std::endl;
}

std::ostream &operator<<(std::ostream &o, Form const &oForm)
{
    o << "[ " << oForm.getName() << " | " << oForm.getFormStatus() << " | " << oForm.getSignGrade() << " | " << oForm.getExecGrade() ;
    return (o);
}

