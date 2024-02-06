#include "Harl.hpp"

// int main()
// {
//     Harl h1;
//     std::string level;

//     std::cout << "ENTER A LEVEL: ";
//     std::cin >> level;
//     h1.complain(level);
//     return (0);
// }

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cout << "Error ❌" << std::endl;
        return (1);
    }
    Harl harl;
    std::string level;
    
    level = argv[1];
    harl.complain(level);
    return (0);
}