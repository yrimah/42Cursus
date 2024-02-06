#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool AFormStatus;
        const int signGrade;
        const int execGrade;

        AForm();
    public:
        AForm(const std::string name, const int signGrade, const int execGrade);
        AForm(AForm const &oAForm);
        AForm &operator=(AForm const &oAForm);
        ~AForm();

        std::string const getName() const;
        bool const getAFormStatus() const;
        int const getSignGrade() const;
        int const getExecGrade() const;

        //Pure virtual
        virtual void execute(Bureaucrat const & executor) const = 0;
        //

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

        class FormNotSigned : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("[ Form not signed ]");
                }
        };
};

std::ostream &operator<<(std::ostream &o, AForm const &oAForm);

#endif