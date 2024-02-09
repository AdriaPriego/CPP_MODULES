/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:08:24 by codespace         #+#    #+#             */
/*   Updated: 2024/02/09 16:50:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = T();
}

template <typename T>
Array<T>::Array( const Array<T> &cpy )
{
    *this = cpy;
}

template <typename T>
Array<T> &Array<T>::operator=( const Array<T> &cpy )
{
    if (_arr)
        delete[] _arr;
    _size = cpy._size;
    _arr = new T[_size]();
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = cpy._arr[i];
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
    delete[] _arr;
}
