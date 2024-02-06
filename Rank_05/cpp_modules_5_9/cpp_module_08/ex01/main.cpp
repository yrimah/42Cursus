#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // sp.addNumber(5);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(Span::FullSpanException &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(Span::NoSpanFound &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}

// int main(void)
// {
//     try
//     {
//         Span oSpan = Span(3);

//         oSpan.addNumber(7);
//         oSpan.addNumber(4);
//         // oSpan.addNumber(14);

//         Span oSpan2 = oSpan;

//         oSpan2.addNumber(42);

//         std::cout << oSpan2.shortestSpan() << std::endl;
//         std::cout << oSpan2.longestSpan() << std::endl;
//     }
//     catch(Span::FullSpanException &e)
//     {
//         std::cout << "Error: " << e.what() << std::endl;
//     }
//     catch(Span::NoSpanFound &e)
//     {
//         std::cout << "Error: " << e.what() << std::endl;
//     }
//     return (0);
// }

// int main(void)
// {
//     try
//     {
//         std::list<int> oList(10000);
//         // std::list<int> oList(2);
//         std::srand(time(NULL));
//         std::generate(oList.begin(), oList.end(), std::rand);

//         Span span(oList.size());

//         span.addNumber(oList.begin(), oList.end());

//         std::cout << span.shortestSpan() << std::endl;
//         std::cout << span.longestSpan() << std::endl;
        
//     }
//     catch(Span::FullSpanException &e)
//     {
//         std::cout << "Error: " << e.what() << std::endl;
//     }
//     catch(Span::NoSpanFound &e)
//     {
//         std::cout << "Error: " << e.what() << std::endl;
//     }
//     return (0);
// }