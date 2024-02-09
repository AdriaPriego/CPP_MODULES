/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:59:34 by codespace         #+#    #+#             */
/*   Updated: 2024/02/09 16:50:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *_arr = NULL;
        unsigned int _size;
    public:
        Array( void );
        Array( unsigned int n );
        Array( const Array &cpy );    
        Array &operator=( const Array &cpy );
        T& operator[](unsigned int n);
        unsigned int size( void ) const;
        ~Array( void );
};
