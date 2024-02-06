/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <yrimah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:02:24 by yrimah            #+#    #+#             */
/*   Updated: 2023/08/22 09:59:31 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "easyfind.hpp"

int main(void)
{
    std::vector<int> a;

    a.push_back(-1);
    a.push_back(20);
    
    a.push_back(42);
    
    std::cout <<  "Vector size: " << a.size() << std::endl;
    
    try
    {
        std::cout << easyfind(a, 42) << std::endl;
    }
    catch(InfoundArgException &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}