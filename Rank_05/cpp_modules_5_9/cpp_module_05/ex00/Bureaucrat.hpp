#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

        Bureaucrat();

    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(Bureaucrat const &oBureaucrat);
        Bureaucrat &operator=(Bureaucrat const &oBureaucrat);
        ~Bureaucrat();

        std::string const &getName() const;
        int const &getGrade() const;

        void increment();
        void decrement();

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


std::ostream &operator<<(std:: ostream &o, Bureaucrat const &oBureaucrat);

#endif