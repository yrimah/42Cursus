#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "----FIRST PART----" << std::endl;

	std::cout << "The memory address of str: " << &str << std::endl;
	std::cout << "The memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address of stringREF: " << &stringREF << std::endl;

	std::cout << "----SECOND PART----" << std::endl;

	std::cout << "The value of the str: " << str << std::endl;
        std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
        std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}
