#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
    std::cout << "--------------------TEST 1--------------------" << std::endl;
    Intern  someRandomIntern;
    AForm*   rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    std::cout << "--------------------TEST 2--------------------" << std::endl;
    Intern  someRandomIntern1;
    AForm*   rrf1;
    rrf1 = someRandomIntern1.makeForm("Invalid", "Bender");

    std::cout << "--------------------TEST 3--------------------" << std::endl;
    Intern  someRandomIntern2;
    AForm*   rrf2;
    rrf2 = someRandomIntern2.makeForm("Shrubbery creation", "Bender");

    std::cout << "--------------------END TEST --------------------" << std::endl;

    return (0);
}
