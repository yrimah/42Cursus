#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

// # include <iostream>
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &oShrubberyCreationForm);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &oShrubberyCreationForm);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;

};

#endif