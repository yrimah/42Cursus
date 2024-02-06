/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <yrimah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:03:39 by yrimah            #+#    #+#             */
/*   Updated: 2023/08/22 09:43:33 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>


class InfoundArgException : public std::exception
{
    public:
        virtual const char* what() const throw ()
        {
            return ("Infound argument!");
        }
};

template<typename T>
int easyfind(T arg1, int arg2)
{
    if (std::find(arg1.begin(), arg1.end(), arg2) != arg1.end())
        return (arg2);
    throw InfoundArgException();
}

#endif