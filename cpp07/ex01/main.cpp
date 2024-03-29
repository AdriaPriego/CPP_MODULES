/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:25:34 by codespace         #+#    #+#             */
/*   Updated: 2024/02/09 14:47:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main(void)
{
    {
        int arr[10];

        for (int i = 0; i < 10; i++)
            arr[i] = i;
        ::iter(arr, 10, print);
    }
    {
        float arr[10] = {1.4, 12.24, 132364.6, 13.423, 41234.24, 123.3, 90.645, 234.13, 1234.41, 1234.1};
        ::iter(arr, 10, print);
    }
}