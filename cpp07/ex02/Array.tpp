/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriego- <apriego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:08:24 by codespace         #+#    #+#             */
/*   Updated: 2024/02/09 18:17:05 by apriego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array( void )
{
    _arr = NULL;
    _size = 0;
}

template <typename T>
Array<T>::Array( unsigned int n )
{
    _arr = new T[n]();
    _size = n;
}

template <typename T>
Array<T>::Array( const Array<T> &cpy )
{
	this->_size = cpy._size;
	this->_arr = new T[ this->_size ]();
	if ( this->_size != 0 )
	{
		for ( unsigned int i = 0; i < this->_size; i++ )
			this->_arr[ i ] = cpy._arr[ i ];
	}
}

template <typename T>
Array<T> &Array<T>::operator=( const Array<T> &cpy )
{
    this->_size = cpy._size;
    if (this->_size != 0)
        delete [] _arr;
    this->_arr = new T[this->_size]();
    if (this->_size != 0)
    {
        for (unsigned int i = 0; i < this->_size; i++)
            this->_arr[i] = cpy._arr[i];
    }
    return (*this);
}

template <typename T>
unsigned int Array<T>::size( void ) const
{
    return (_size);
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
    if (n >= _size)
        throw std::out_of_range("Index out of range");
    return _arr[n];
}

template <typename T>
Array<T>::~Array( void )
{
    if (_arr)
        delete[] _arr;
}
