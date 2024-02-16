/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:44 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 10:47:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid Format: ./btc [file]" << std::endl;
        return (1);
    }
    std::ifstream file;
    (void)argv;
    file.open("data.csv", std::ios::in);
    if (!file)
    {
        std::cout << "BD not found" << std::endl;
        return (1);
    }
    std::vector<std::string> fileVector;
    std::string line;
    while (getline(file, line))
    {
        fileVector.push_back(line);
    }
    file.close();
    std::vector<t_exchange> dataBD = parseBD(fileVector);
    file.open(argv[1], std::ios::in);
    if (!file)
    {
        std::cout << "File not found" << std::endl;
        return (1);
    }
    fileVector.clear();
    while (getline(file, line))
    {
        fileVector.push_back(line);
    }
    file.close();
    doExchange(dataBD, fileVector);
    return (0);       
}