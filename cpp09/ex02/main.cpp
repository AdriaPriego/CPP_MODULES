/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:15:34 by codespace         #+#    #+#             */
/*   Updated: 2024/02/19 11:50:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <list>
#include <climits>

int isInt(const std::string& literal)
{
    size_t i = 0;
    long test = 0;
    int neg = 1;
    if (literal[0] == '-')
    {
        i = 1;
        neg = -1;
    }
    while (i < literal.length())
    {
        if (isdigit(literal[i]) == 0)
            return (0);
        test *= 10;
        test += literal[i] - '0';
        if (test * neg > INT_MAX || test * neg < INT_MIN)
            return (0);
        i++;
    }
    return (1);
}

int countOcurs(const std::string literal, const char toFind)
{
    int ocurs = 0;

    for (int i = 0; literal[i]; i++)
    {
        if (literal[i] == toFind)
            ocurs++;
    }
    return (ocurs);
}

std::list<unsigned int> convertToList(char **av, int ac)
{
    std::list<unsigned int> lst;

    for (int i = 1; i < ac; i++)
    {
        if (isInt(av[i]))
        {
            std::string literal(av[i]);
            int numint = std::atoi(av[i]);

            if (numint < 0)
                throw std::out_of_range("Negative number");
            lst.push_back(numint);
        }
        else
            throw std::out_of_range("Not a valid input");
    }
    return (lst);
}

void insertionSort(std::list<unsigned int>& lst)
{
    for (std::list<unsigned int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        unsigned int key = *it;
        std::list<unsigned int>::iterator jt = it;
        std::list<unsigned int>::iterator temp;
        while (jt != lst.begin() && *(--jt) > key)
        {
            temp = jt;
            std::swap(*jt, *(++temp));
        }
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Bad arguments." << std::endl;
        return (1);
    }
    if (ac == 2)
    {
        if (isInt(av[1]))
        {
            std::string literal(av[1]);
            int numint = std::atoi(av[1]);

            if(countOcurs(av[1], '-') == 0 && numint == -1)
                std::cout << "Int overflow" << std::endl;
            else if (literal.length() - countOcurs(literal, '0') > 2 && numint == 0)
                std::cout << "Int underflow" << std::endl;
        }
        else
            std::cout << "Not a valid number" << std::endl;
    }
    else
    {
        std::list<unsigned int> lst;

        try
        {
            lst = convertToList(av, ac);
            insertionSort(lst);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
    return (0);
}