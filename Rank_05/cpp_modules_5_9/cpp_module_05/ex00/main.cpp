#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("TEST0", 160);
        Bureaucrat b2("TEST1", -10);
        Bureaucrat b3("TEST2", 150);
        Bureaucrat b4("TEST3", 1);

        b4.increment();
        // b3.decrement();
        std::cout << b3 << b4 << std::endl;
    }
    // catch(Bureaucrat::GradeTooLowException & e)
    // {
    //     std::cout << "[ Exception ] : " << e.what() << std::endl;
    // }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "[ Exception ] : " << e.what() << std::endl;
    }
    return (0);
}