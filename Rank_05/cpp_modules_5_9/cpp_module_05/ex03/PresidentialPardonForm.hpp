#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

// # include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

        PresidentialPardonForm();

    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &oPresidentialPardonForm);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &oPresidentialPardonForm);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;

};

#endif