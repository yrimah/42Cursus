#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// g++    -c -o Base.o Base.cpp
// g++    -c -o main.o main.cpp
// g++ -Wall -Wextra -Werror main.o Base.o -o program

Base*   generate(void)
{
    int rand;

    rand = std::rand();
    rand++;
    if (std::rand() % 3 == 0)
        return (new A);
    else if (std::rand() % 3 == 1)
        return (new B);
    else
        return (new C);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Not valid." << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    } catch(const std::exception& e) {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    } catch(const std::exception& e) {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    } catch(const std::exception& e) {}
}

int     main(void)
{
    std::cout << "----------TEST BEGIN----------" << std::endl;
    
    Base*   base1 = generate();
    std::cout << "base1* = ";
    identify(base1);
    std::cout << "base1& = ";
    identify(*base1);
    std::cout << std::endl;

    Base*   base2 = generate();
    std::cout <<"base2* = ";
    identify(base2);
    std::cout << "base2& = ";
    identify(*base2);
    std::cout << std::endl;

    Base*   base3 = generate();
    std::cout << "base3* = ";
    identify(base3);
    std::cout << "base3& = ";
    identify(*base3);
    std::cout << std::endl;

    Base*   base4 = generate();
    std::cout << "base4* = ";
    identify(base4);
    std::cout << "base4& = ";
    identify(*base4);
    std::cout << std::endl;

    delete base1;
    delete base2;
    delete base3;
    delete base4;

    std::cout << "----------TEST END----------" << std::endl;
    return (0);
}