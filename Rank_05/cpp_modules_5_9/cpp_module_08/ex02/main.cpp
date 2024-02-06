#include "MutantStack.hpp"

int main()
{
    std::cout << "------GIVEN TEST: MUTANTSTACK------" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "------MORE TESTS: LIST------" << std::endl;
    std::list<int> oList;
    oList.push_back(5);
    oList.push_back(17);
    std::cout << oList.back() << std::endl;
    oList.pop_back();
    std::cout << oList.size() << std::endl;
    oList.push_back(3);
    oList.push_back(5);
    oList.push_back(737);
    //[...]
    oList.push_back(0);
    std::list<int>::iterator it_list = oList.begin();
    std::list<int>::iterator ite_list = oList.end();
    ++it_list;
    --it_list;
    while (it_list != ite_list)
    {
        std::cout << *it_list << std::endl;
        ++it_list;
    }
    std::list<int> s_list(oList);

    return (0);
}

// int main()
// {
//     std::list<int> oList;
//     oList.push_back(5);
//     oList.push_back(17);
//     std::cout << oList.back() << std::endl;
//     oList.pop_back();
//     std::cout << oList.size() << std::endl;
//     oList.push_back(3);
//     oList.push_back(5);
//     oList.push_back(737);
//     //[...]
//     oList.push_back(0);
//     std::list<int>::iterator it = oList.begin();
//     std::list<int>::iterator ite = oList.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::list<int> s(oList);
//     return 0;
// }