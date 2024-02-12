/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:26:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/12 15:51:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <numeric>

class Span
{
    private:
        std::list<unsigned int> _list;
        unsigned int _size;
    public:
        Span( void );
        Span ( unsigned int n );
        Span ( const Span &cpy );
        Span &operator=( const Span &cpy );
        void addNumber( unsigned int n );
        void addNumbers( unsigned int begin, unsigned end );
        unsigned int shortestSpan( void );
        unsigned int longestSpan( void );
        unsigned int getSize( void );
        void printList( void );
        ~Span( void );
        template <typename InputIterator>
        Span(InputIterator first, InputIterator last) : _list(first, last)
        {
            _size = std::distance(first, last);
        }
};
