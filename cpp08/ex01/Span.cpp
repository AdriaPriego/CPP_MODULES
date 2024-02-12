/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:26:45 by codespace         #+#    #+#             */
/*   Updated: 2024/02/12 15:51:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <climits>
#include <algorithm>

Span::Span( void )
{
    _size = 0;
}

Span::Span( unsigned int n )
{
    _size = n;
}

Span::Span ( const Span &cpy )
{
    *this = cpy;
}

Span &Span::operator=( const Span &cpy )
{
    if (this != &cpy)
    {
        _size = cpy._size;
        _list.clear();
        _list = cpy._list;
    }
    return (*this);
}

void Span::addNumbers( unsigned int begin, unsigned end )
{
    unsigned int dis;

    begin < end ? dis = end - begin : dis = begin - end;
    if (dis > _size)
        throw std::out_of_range("Maximum numbers of nodes");
    if (end < begin)
    {
        for (unsigned int i = begin; i > end; i--)
            _list.push_back(i);
    }
    else
    {
        for (unsigned int i = begin; i < end; i++)
            _list.push_back(i);
    }
}

void Span::addNumber( unsigned int n )
{
    if (_list.size() + 1 > _size)
        throw std::out_of_range("Maximum numbers of nodes");
    _list.push_back(n);
}

unsigned int Span::shortestSpan( void )
{
    std::list<unsigned int>::iterator init = _list.begin();
    std::list<unsigned int>::iterator next = _list.begin();
    unsigned int dist = UINT_MAX;
    unsigned int auxdis = 0;
    
    while (init != _list.end())
    {
        next++;
        while (next != _list.end())
        {
            *init < *next ? auxdis = *next - *init : auxdis = *init - *next;
            if (auxdis < dist)
                dist = auxdis;
            next++;
        }
        init++;
        next = init;
    }
    return (dist);
}

unsigned int Span::longestSpan( void )
{
    std::list<unsigned int>::iterator min = std::min_element(_list.begin(), _list.end());
    std::list<unsigned int>::iterator max = std::max_element(_list.begin(), _list.end());
    return ( *max - *min );
}

unsigned int Span::getSize( void )
{
    return (_size);
}

void Span::printList( void )
{
    for (std::list<unsigned int>::iterator it = _list.begin(); it != _list.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

Span::~Span( void )
{
    std::cout << "Destroy" << std::endl;
}