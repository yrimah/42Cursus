#include "RobotomyRequestForm.hpp"

// RobotomyRequestForm::RobotomyRequestForm()
// {
//     std::cout << "RobotomyRequestForm default constructor called." << std::endl;
// }

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm parametrized constructor called." << std::endl;
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &oRobotomyRequestForm) : AForm(oRobotomyRequestForm)
{
    std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
    this->target = oRobotomyRequestForm.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &oRobotomyRequestForm)
{
    this->target = oRobotomyRequestForm.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getAFormStatus())
        throw AForm::FormNotSigned();
    if (this->getExecGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();
    else
    {
        static int counter;
        if (counter % 2 == 0)
        {
            std::cout << "Driiiiiiiilling noooooooiiiiiises ... " << std::endl;
            std::cout << "[ " << this->target << " ] : " << "has been robotomized successfully." << std::endl;
        }
        else
            std::cout << "Robotomy failed" << std::endl;
        counter++;
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}