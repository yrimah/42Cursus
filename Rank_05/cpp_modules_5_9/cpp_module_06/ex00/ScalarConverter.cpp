#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& oScalarConverter)
{ 
    *this = oScalarConverter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& oScalarConverter)
{
    (void)oScalarConverter;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(const std::string& literal)
{
    std::string pseudoLiterals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

    std::string char_literal = "";
    int int_literal = 0;
    float float_literal = 0;
    double double_literal = 0;

    // Check for char //
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        char_literal = literal[0];
        std::cout << "char: " << char_literal << std::endl;
        std::cout << "int: " << static_cast<int>(char_literal[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(char_literal[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(char_literal[0]) << ".0" << std::endl;
        
        return;
    }

    // Check if literal is a number or give it 0 //
    
    int_literal = std::atoi(literal.c_str());

    // Check if literal is float or int or double //

    if (literal[literal.length() - 1] == 'f')
    {
        float_literal = std::atof(literal.c_str());
        double_literal = static_cast<double>(float_literal);
    }
    else
    {
        double_literal = std::atof(literal.c_str());
        float_literal = static_cast<float>(double_literal);
    }

    // Check for pseudo literals : nan - nanf ... //

    for (int i = 0; i < 6; i++)
    {
        if (literal == pseudoLiterals[i])
        {
            char_literal = "imposible";
            break;
        }
    }

    if (char_literal == "" && std::isprint(int_literal))
    {
        char_literal = "'";
        char_literal += static_cast<char>(int_literal);
        char_literal += "'";
    }
    else if (char_literal == "")
    {
        char_literal = "Non displayable";
    }

    std::cout << "char: " << char_literal << std::endl;

    if (char_literal == "imposible")
        std::cout << "int: imposible" << std::endl;
    else
        std::cout << "int: " << int_literal << std::endl;

    if (char_literal == "imposible" && float_literal == 0)
    {
        std::cout << "float: imposible" << std::endl;
        std::cout << "double: imposible" << std::endl;
    }
    else
    {
        if (char_literal != "imposible" && float_literal - static_cast<int>(float_literal) == 0)
        {
            std::cout << "float: " << float_literal << ".0f" << std::endl;
            std::cout << "double: " << double_literal << ".0" << std::endl;
        }
        else
        {
            std::cout << "float: " << float_literal << "f" << std::endl;
            std::cout << "double: " << double_literal << std::endl;
        }
    }

}