/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:12 by codespace         #+#    #+#             */
/*   Updated: 2024/02/19 16:34:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

std::vector<unsigned int> convertToVector(char **av, int ac)
{
    std::vector<unsigned int> lst;

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

std::deque<unsigned int> convertToDeque(char **av, int ac)
{
    std::deque<unsigned int> lst;

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
