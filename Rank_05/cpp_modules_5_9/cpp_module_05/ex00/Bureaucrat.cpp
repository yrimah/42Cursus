#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    std::cout << "Bureaucrat parametrized constructor called." << std::endl;
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
        {
            this->grade = grade;
            std::cout << "Bureaucrat grade applied." << std::endl;
        }
    }
    catch (std::exception & e)
    {
        std::cout << "[ Exception ] : " << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &oBureaucrat) : name(oBureaucrat.name)
{
    std::cout << "Bureaucrat copy constructor called." << std::endl;
    this->grade = oBureaucrat.grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &oBureaucrat)
{
    std::cout << "Bureaucrat copy assignment operator called." << std::endl;
    this->grade = oBureaucrat.grade;
    return (*this);
}

void Bureaucrat::increment()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrement()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::string const &Bureaucrat::getName() const
{
    return (this->name);
}

int const &Bureaucrat::getGrade() const
{
    return (this->grade);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called." << std::endl;
}

std::ostream &operator<<(std:: ostream &o, Bureaucrat const &oBureaucrat)
{
    o << oBureaucrat.getName() << ", " << oBureaucrat.getGrade() << ".";
    return (o);
}