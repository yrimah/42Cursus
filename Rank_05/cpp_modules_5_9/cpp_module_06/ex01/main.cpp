#include "Serializer.hpp"

// g++ -c -o Serializer.o Serializer.cpp
// g++ -c -o main.o main.cpp
// g++ -Wall -Wextra -Werror main.o Serializer.o -o program

int main()
{
    // Data* d1 = new Data();
    // Data* d2;
    // uintptr_t ptr;

    // ptr = Serializer::serialize(d1);
    // d2 = Serializer::deserialize(ptr);
    // std::cout << d1 << std::endl;
    // std::cout << d2 << std::endl;

    Data* d1 = new Data();
    
    d1->u_id = 1337;
    std::cout << "BEFORE OPERATIONS : " << &d1 << std::endl;
    std::cout << "---->USER ID : " << d1->u_id << std::endl;

    d1 = Serializer::deserialize(Serializer::serialize(d1));
    std::cout << "AFTER OPERATIONS : " << &d1 << std::endl;
    std::cout << "---->USER ID : " << d1->u_id << std::endl;

    delete d1;

    return (0);
}