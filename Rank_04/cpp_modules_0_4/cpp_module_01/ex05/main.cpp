#include "Harl.hpp"

int main()
{
    Harl h1;
    std::string level;

    std::cout << "ENTER A LEVEL: ";
    std::cin >> level;
    h1.complain(level);
    return (0);
}