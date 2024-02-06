// #include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b3("TEST2", 13);
        Form f3("FORM3", 10, 40);
        
        // Not signed yet
        std::cout << f3.getFormStatus() << std::endl;

        // Sign the form
        f3.beSigned(b3); // change the bureaucrat grade to a lower one than 10 to sign the form
        std::cout << f3.getFormStatus() << std::endl;

        b3.signForm(f3);
    }
    catch(Form::GradeTooHighException & e)
    {
        std::cout << "[ Exception ] : " << e.what() << std::endl;
    }
    catch(Form::GradeTooLowException & e)
    {
        std::cout << "[ Exception ] : " << e.what() << std::endl;
    }

    return (0);
}