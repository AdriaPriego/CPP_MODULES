/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:25:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/09 14:42:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>

template <typename T>
void print(T think)
{
    std::cout << think << std::endl;
}

template <typename T>
void iter(T *arr, size_t size, void (*f)(T))
{
    for (size_t i = 0; i < size; i++)
        f(arr[i]);
}
