/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:38 by codespace         #+#    #+#             */
/*   Updated: 2024/02/19 13:16:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int dayDifference(const struct tm &date1, const struct tm &date2)
{
    int date1Acum = date1.tm_year * 365 + date1.tm_mon * 30 + date1.tm_mday;
    int date2Acum = date2.tm_year * 365 + date2.tm_mon * 30 + date2.tm_mday;

    return (date1Acum - date2Acum);
}

std::list<std::string> split(const std::string& s, char delimiter)
{
    std::list<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
        if (!token.empty())
            tokens.push_back(token);
    return tokens;
}

std::list<t_exchange> parseBD(std::list<std::string> fileList)
{
    std::list<std::string>::iterator itFile = fileList.begin();
    std::list<t_exchange> exc;

    if (*itFile == "date,exchange_rate")
        itFile++;
    while (itFile != fileList.end())
    {
        std::list<std::string> test = split(*itFile, ',');
        std::list<std::string>::iterator itLine = test.begin();
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

t_exchange parseLine(std::string line)
{
    t_exchange exc;
    std::list<std::string> lineSplit = split(line, '|');

    if (lineSplit.size() != 2)
        throw std::invalid_argument("Error: bad input => " + line);
    if (!strptime((*lineSplit.begin()).c_str(), "%Y-%m-%d ", &exc.tm))
        throw std::invalid_argument(line + "  Error: not a valid date.");
    exc.eRate = std::atof(&((*(++lineSplit.begin()))[1]));
    if (exc.eRate > 1000)
        throw std::out_of_range(line + "  Error: too large a number.");
    if (exc.eRate < 0)
        throw std::out_of_range(line + "  Error: not a positive number.");
    return (exc);
}

void doExchange(std::list<t_exchange> dataBD, std::list<std::string> fileList)
{
    std::list<std::string>::iterator it = fileList.begin();
    std::list<t_exchange>::iterator minDate;
    int diff = INT_MAX;
    int auxdiff;

    if (*it == "date | value")
        it++;
    while (it != fileList.end())
    {
        try
        {
            t_exchange exc = parseLine(*it);
            std::list<t_exchange>::iterator itDB = dataBD.begin();
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
            std::cout << exc.tm.tm_year + 1900 << "-" << exc.tm.tm_mon + 1 << "-" << exc.tm.tm_mday << " => ";
            std::cout << exc.eRate << " = " << exc.eRate * (*minDate).eRate << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        } 
        it++;
    }
}
