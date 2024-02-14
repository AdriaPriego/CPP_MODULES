/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:44 by codespace         #+#    #+#             */
/*   Updated: 2024/02/14 18:23:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>
#include "BitcoinExchange.hpp"

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
        tokens.push_back(token);
    return tokens;
}

int parseFile(std::vector<std::string> fileVector)
{
    std::vector<std::string> test;
    std::vector<std::string>::iterator init = fileVector.begin();
    std::vector<t_exchange> exc;
    if (*init == "date | value")
        init++;
    while (init != fileVector.end())
    {
        std::vector<std::string> test = split(*init, '|');
        std::vector<std::string>::iterator init2 = test.begin();
        bool first = true;
        std::cout << *init << std::endl;
        t_exchange testing;
        while (init2 != test.end())
        {
            if (first)
            {
                if (strptime((*init2).c_str(), "%Y-%m-%d ", &testing.tm))
                {
                    std::cout << "Año: " << testing.tm.tm_year + 1900 << '\n';
                    std::cout << "Mes: " << testing.tm.tm_mon + 1 << '\n';
                    std::cout << "Día: " << testing.tm.tm_mday << '\n';
                }
                else
                    std::cout << "Bad date." << std::endl;
            }
            else
            {
                    testing.qtt = std::atof(&(*init2)[1]);
                    if (testing.qtt > INT_MAX || testing.qtt <= 0)
                        std::cout << "Bad Number" << std::endl;
                    else
                        std::cout << testing.qtt << std::endl;
            }
            first = false;
            init2++;
        }
        exc.push_back(testing);
        init++;
    }
    return (0);
}

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
    std::vector<std::string> fileVector;
    std::string line;
    while (getline(file, line))
    {
        fileVector.push_back(line);
    }
    file.close();
    parseFile(fileVector); 
    return (0);       
}