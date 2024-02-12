/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:13:10 by codespace         #+#    #+#             */
/*   Updated: 2024/02/12 16:14:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack( void );
        MutantStack( const MutantStack &cpy );
        MutantStack& operator=( const MutantStack &cpy );
        ~MutantStack( void );

        typedef typename std::stack< T >::container_type::iterator iterator;
        iterator begin( void );
        iterator end( void );
};

template <typename T>
MutantStack< T >::MutantStack( void ): std::stack<T>(){}

template <typename T>
MutantStack< T >::MutantStack( const MutantStack &cpy ): std::stack<T>(cpy){}

template <typename T>
MutantStack< T >& MutantStack< T >::operator=( const MutantStack &cpy )
{
    return (std::stack< T >::operator=(cpy));
}

template <typename T>
MutantStack< T >::~MutantStack( void ) {}

template <typename T>
typename MutantStack< T >::iterator MutantStack< T >::begin( void )
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack< T >::iterator MutantStack< T >::end( void )
{
    return (this->c.end());
}