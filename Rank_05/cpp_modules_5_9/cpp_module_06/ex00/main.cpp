#include "ScalarConverter.hpp"

// g++ -c -o ScalarConverter.o ScalarConverter.cpp  
// g++ -c -o main.o main.cpp  
// g++ -Wall -Wextra -Werror main.o ScalarConverter.o -o convert

int main(int argc, char **argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    return (0);
}