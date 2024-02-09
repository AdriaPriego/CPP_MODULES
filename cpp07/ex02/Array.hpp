/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriego- <apriego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:59:34 by codespace         #+#    #+#             */
/*   Updated: 2024/02/09 18:13:43 by apriego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *_arr;
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

#include "Array.tpp"
