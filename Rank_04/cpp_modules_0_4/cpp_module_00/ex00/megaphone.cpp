#include <iostream>

std::string ft_toupper(const std::string& str)
{
    int count = -1;
    std::string result(str.size(), '\0');
    while (++count < str.size())
        result[count] = std::toupper(str[count]);
    return (result);
}

int main(int argc, char **argv)
{
    (void)argc;
    int count = 0;
    
    if (argc > 1)
    {
        while (++count < argc)
        {
            std::string upper = ft_toupper(argv[count]);
            std::cout << upper + " ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}