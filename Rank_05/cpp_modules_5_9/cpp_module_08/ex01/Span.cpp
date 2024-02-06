/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrimah <yrimah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:41:44 by yrimah            #+#    #+#             */
/*   Updated: 2023/08/22 10:23:07 by yrimah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    // std::cout << "Default constructer" << std::endl;
}

Span::Span(unsigned int N)
{
    this->N = N;
    this->span = std::list<int>();
}

Span::Span(Span const &oSpan)
{
        this->N = oSpan.N;
        this->span = oSpan.span;
}

Span &Span::operator=(Span const &oSpan)
{
    if (this != &oSpan)
    {
        this-> N = oSpan.N;
        this->span = oSpan.span;
    }
    return (*this);
}

Span::~Span()
{
    // std::cout << "Destructor called" << std::endl;
}

void Span::addNumber(int number)
{
    if (this->span.size() < this->N)
        this->span.push_back(number);
    else if (this->span.size() == 0)
        throw NoSpanFound();
    else
        throw FullSpanException();
}

int Span::longestSpan(void) const
{
    if (span.size() == 0 || span.size() == 1)
        throw NoSpanFound();
    
    std::list<int>::const_iterator span_it;

    int max = *(std::max_element(span.begin(), span.end()));
    int min = *(std::min_element(span.begin(), span.end()));

    // std::cout << std::endl << "MAX = " << max << std::endl;
    // std::cout << std::endl << "MIN = " << min << std::endl << std::endl;
    
    return (max - min);
}

int Span::shortestSpan(void) const
{
    if (span.size() == 0 || span.size() == 1)
        throw NoSpanFound();
    
    std::list<int>::const_iterator span_it1;
    std::list<int>::const_iterator span_it2;

    span_it1 = span.begin();
    span_it2 = span.begin();

    int diff = abs(*(std::max_element(span.begin(), span.end())));
    
    for (span_it1 = span.begin(); span_it1 != span.end(); span_it1++)
    {
        for(span_it2 = span.begin(); span_it2 != span.end(); span_it2++)
        {
            if (span_it1 == span_it2)
                continue;
            if (diff > abs(*(span_it1) - *(span_it2)))
                diff = abs(*(span_it1) - *(span_it2));
        }
    }
    return (diff);
}

void Span::addNumber(std::list<int>::iterator span_it_begin, std::list<int>::iterator span_it_end)
{
    if (this->span.size() < this->N)
        span.insert(span.end(), span_it_begin, span_it_end);
    else if (this->span.size() == 0)
        throw NoSpanFound();
    else
        throw FullSpanException();
}

const std::list<int> &Span::getSpan(void) const
{
    return (this->span);
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
    for (std::list<int>::const_iterator list_it = span.getSpan().begin(); list_it != span.getSpan().end(); list_it++)
        os << *list_it;
    return (os);
}