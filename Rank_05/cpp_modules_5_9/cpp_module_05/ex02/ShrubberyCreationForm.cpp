#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm()
// {
//     std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
// }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm parametrized constructor called." << std::endl;
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &oShrubberyCreationForm) : AForm(oShrubberyCreationForm)
{
    std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
    this->target = oShrubberyCreationForm.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &oShrubberyCreationForm)
{
    this->target = oShrubberyCreationForm.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getAFormStatus())
        throw AForm::FormNotSigned();
    if (this->getExecGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();
    
    std::fstream file;
    file.open(this->target + "_shrubbery", std::ios::out);

    //
    file << "             ,-'          __,,-- \\" << std::endl;
    file << "           ,\'    __,--\"\"\"\"dF      /" << std::endl;
    file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    file << "     (     ,-'                  `" << std::endl;
    file << "      `._,'     _   _             ;" << std::endl;
    file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    file << "        \\   `Hb  HH  HH  HH" << std::endl;
    file << "         \\   Hb, HH  HH  HH" << std::endl;
    file << "          )   \"Hb HH  HH  HH" << std::endl;
    file << "        ,-'     \"HHHHHHHHHHH" << std::endl;
    file << "      ,\'           \"\"\"HHHHHH\"" << std::endl;
    file << "    ,-'                  \"\"\"\"" << std::endl;
    file << "  ,'" << std::endl;
    //
    file.close();
    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}