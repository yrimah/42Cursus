#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *add, int length, void (*func)(T &elem))
{
    int i = -1;
    while (++i < length)
        func(add[i]);
}

// for the main test

template<typename T>
void display(T elem)
{
    std::cout << elem << std::endl;
}

#endif
