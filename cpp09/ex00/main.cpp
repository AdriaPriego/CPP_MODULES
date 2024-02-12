/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:44 by codespace         #+#    #+#             */
/*   Updated: 2024/02/12 17:27:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid Format: ./btc [file]" << std::endl;
        return (1);
    }
    std::ifstream file;

    file.open(argv[1], std::ios::in);
    if (!file)
    {
        std::cout << "Invalid File" << std::endl;
        return (1);
    }
    char x;
    while (!file.eof())
    {
        file >> x;
        std::cout << x;
    }
    std::cout << std::endl;
    file.close();
    return (0);       
}