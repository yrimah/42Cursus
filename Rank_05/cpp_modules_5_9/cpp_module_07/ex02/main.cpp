#include "Array.hpp"
// #include <cmath>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int>numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

int main(void)
{
    Array<int> ar1(5);

    for (unsigned int i = 0; i < ar1.size(); i++)
        ar1[i] = i * 2;
    std::cout << ar1 << std::endl;

    Array<int> ar2(ar1);
    std::cout << ar2 << std::endl;

    Array<int> ar3 = ar1;
    std::cout << ar2 << std::endl;
    
    Array<char> c_arr(4);

    try
    {
        c_arr[0] = '1';
        c_arr[1] = '3';
        c_arr[2] = '3';
        c_arr[3] = '7';
        //c_arr[4] = '*';
        c_arr[-1] = '9';
    }
    catch(Array<char>::OutOfBoundException &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}