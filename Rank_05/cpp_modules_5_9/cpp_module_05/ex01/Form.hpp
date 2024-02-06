#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool formStatus;
        const int signGrade;
        const int execGrade;

        Form();
    public:
        Form(const std::string name, const int signGrade, const int execGrade);
        Form(Form const &oForm);
        Form &operator=(Form const &oForm);
        ~Form();

        std::string const getName() const;
        bool const getFormStatus() const;
        int const getSignGrade() const;
        int const getExecGrade() const;

        void beSigned(Bureaucrat const &Bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("[ Grade too high ]");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("[ Grade too low ]");
                }
        };
};

std::ostream &operator<<(std::ostream &o, Form const &oForm);

#endif