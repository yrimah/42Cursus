#include "iter.hpp"

void add_one(int &number)
{
    number += 1;
}

int main(void)
{
    int a[4] = {1337, 42, 9, 5};
    std::string b[5] = {"BG", "KH", "MED", "RABAT", "MARRAKECH"};
    
    std::cout << "----------FIRST TEST----------" << std::endl;
    iter(a, 4, add_one);
    iter(a, 4, display);
    std::cout << "----------SECOND TEST----------" << std::endl;
    iter(b, 4, display);

    return (0);
}