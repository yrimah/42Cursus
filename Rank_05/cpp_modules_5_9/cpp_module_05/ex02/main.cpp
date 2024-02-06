#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main ()
{
    try
    {
        Bureaucrat bureaucrat("BUREAUCRAT", 13);
        ShrubberyCreationForm f1("Shrubbery");
        RobotomyRequestForm f2("Robotomy");
        PresidentialPardonForm f3("President");

        std::cout << "--------------- TEST 1 ( Shrubbery ) ---------------" << std::endl;
        f1.beSigned(bureaucrat);
        bureaucrat.signAForm(f1);
        bureaucrat.executeForm(f1);

        f1.execute(bureaucrat);
        std::cout << "--------------- TEST 2 ( Robotomy ) ---------------" << std::endl;
        f2.beSigned(bureaucrat);
        bureaucrat.signAForm(f2);
        bureaucrat.executeForm(f2);
        std::cout << "--------------- TEST 3 ( President ) ---------------" << std::endl;
        f3.beSigned(bureaucrat);
        bureaucrat.signAForm(f3);
        bureaucrat.executeForm(f3);
        std::cout << "--------------- END TESTS ---------------" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "[ Exception ] : " << e.what() << std::endl;
    }
    return (0);
}
