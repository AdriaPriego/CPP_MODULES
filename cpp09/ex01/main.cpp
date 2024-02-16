/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:55:54 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 17:30:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Invalid Argument" << std::endl;
        return (1);  
    }
    try
    {
        std::cout << reversePolishNotation(av[1]) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
