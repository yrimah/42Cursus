#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

// # include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

        RobotomyRequestForm();

    public:
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &oRobotomyRequestForm);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &oRobotomyRequestForm);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;

};

#endif