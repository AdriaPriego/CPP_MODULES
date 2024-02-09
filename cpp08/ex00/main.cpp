/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:45:04 by codespace         #+#    #+#             */
/*   Updated: 2024/02/09 17:53:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::vector < int > vec;
    std::list < int > lis;
    std::deque < int > deq;

    for (int i = 0; i < 7; i++)
    {
        vec.push_back(i);
        lis.push_back(i);
        deq.push_back(i);
    }
    
    try
    {
        easyfind(vec, 12);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        easyfind(lis, 123);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        easyfind(deq, 431);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        try
    {
        easyfind(vec, 6);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        easyfind(lis, 6);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        easyfind(deq, 6);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}