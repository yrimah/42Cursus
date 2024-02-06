#include "PhoneBook.hpp"

// int main()
// {
//     // std::string text;
//     // int text;

//     // std::cin >> text;
//     // std::getline(std::cin, text);
//     // if (!std::cin.good())
//     // {
//         std::cout << std::setw(20) << "Error..." << std::endl;
//         // retrun (1)
//     // }
//     // Ignore remaining input characters including newline
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     // std::cout << text << std::endl;
//     return (0);
// }

int main(void)
{
    PhoneBook pb;
    std::string cmd;
    
    cmd = "";
    pb.setupPhonebook();
    while (cmd != "EXIT")
    {
        if (cmd == "ADD")
            pb.add();
        else if (cmd == "SEARCH")
        {
            pb.showContacts();
            pb.search();
        }
        std::cout << "▶ Your choice: " << std::flush;
        std::cin >> cmd;
    }
    std::cout << "Exiting from the program...✅";
    return 0;
}