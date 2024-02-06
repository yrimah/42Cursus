#include "whatever.hpp"

// int main()
// {
//     int a = 42;
//     int b = 1337;

//     std::cout << "----BEGIN TEST----" << std::endl;
//     std::cout << "Value of a is : " << a << std::endl;
//     std::cout << "Value of b is : " << b << std::endl;

//     std::cout << "----SWAP TEST----" << std::endl;
//     swap(a, b);
//     std::cout << "Value of a is : " << a << std::endl;
//     std::cout << "Value of b is : " << b << std::endl;
    
//     std::cout << "----MAX/MIN TEST----" << std::endl;
//     std::cout << "Max : " << max(a, b) << std::endl;
//     std::cout << "Min : " << min(a, b) << std::endl;

//     return (0);
// }

int main( void )
{
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}
