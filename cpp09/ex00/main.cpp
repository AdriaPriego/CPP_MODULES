/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:44 by codespace         #+#    #+#             */
/*   Updated: 2024/02/19 13:16:43 by codespace        ###   ########.fr       */
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
    std::list<std::string> fileList;
    std::string line;
    while (getline(file, line))
    {
        fileList.push_back(line);
    }
    file.close();
    std::list<t_exchange> dataBD = parseBD(fileList);
    file.open(argv[1], std::ios::in);
    if (!file)
    {
        std::cout << "File not found" << std::endl;
        return (1);
    }
    fileList.clear();
    while (getline(file, line))
    {
        fileList.push_back(line);
    }
    file.close();
    doExchange(dataBD, fileList);
    return (0);       
}