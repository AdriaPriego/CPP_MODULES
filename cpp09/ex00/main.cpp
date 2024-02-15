/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:44 by codespace         #+#    #+#             */
/*   Updated: 2024/02/15 14:34:59 by codespace        ###   ########.fr       */
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

std::vector<t_exchange> parseBD(std::vector<std::string> fileVector)
{
    std::vector<std::string>::iterator itFile = fileVector.begin();
    std::vector<t_exchange> exc;
    if (*itFile == "date,exchange_rate")
        itFile++;
    while (itFile != fileVector.end())
    {
        std::vector<std::string> test = split(*itFile, ',');
        std::vector<std::string>::iterator itLine = test.begin();
        bool first = true;
        bool valid = true;        
        t_exchange testing;
        while (itLine != test.end())
        {
            if (first)
            {
                if (!strptime((*itLine).c_str(), "%Y-%m-%d", &testing.tm))
                    valid = false;
            }
            else
            {
                testing.eRate = std::atof((*itLine).c_str());
                if (testing.eRate > INT_MAX || testing.eRate < 0)
                    valid = false;
            }
            first = false;
            itLine++;
        }
        if (valid == true)
            exc.push_back(testing);
        itFile++;
    }
    return (exc);
}
//2011-01-03 | 3
t_exchange parseLine(std::string line)
{
    t_exchange exc;
    std::vector<std::string> lineSplit = split(line, '|');

    if (lineSplit.size() != 2)
        throw std::invalid_argument("Error: bad input => " + line);
    if (!strptime(lineSplit[0].c_str(), "%Y-%m-%d ", &exc.tm))
        throw std::invalid_argument(line + "  Error: not a valid date.");
    exc.eRate = std::atof(&(lineSplit[1][1]));
    if (exc.eRate > 1000)
        throw std::out_of_range(line + "  Error: too large a number.");
    if (exc.eRate < 0)
        throw std::out_of_range(line + "  Error: not a positive number.");
    return (exc);
}

void doExchange(std::vector<t_exchange> dataBD, std::vector<std::string> fileVector)
{
    std::vector<std::string>::iterator it = fileVector.begin();
    std::vector<t_exchange>::iterator minDate;
    int diff = INT_MAX;
    int auxdiff;
    if (*it == "date | value")
        it++;
    while (it != fileVector.end())
    {
        try
        {
            t_exchange exc = parseLine(*it);
            std::vector<t_exchange>::iterator itDB = dataBD.begin();
            while (itDB != dataBD.end())
            {
                auxdiff = dayDifference(exc.tm, (*itDB).tm);
                if (auxdiff < diff && auxdiff >= 0)
                {
                    diff = auxdiff;
                    minDate = itDB;
                }
                itDB++;
            }
            std::cout << exc.tm.tm_year + 1900 << "-" << exc.tm.tm_mon + 1 << "-" << exc.tm.tm_mday << " => " << exc.eRate << " = " << exc.eRate * (*minDate).eRate << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        } 
        it++;
    }
}


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