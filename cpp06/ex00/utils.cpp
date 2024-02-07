/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:33:53 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 22:37:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

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

int isInt(const std::string& literal)
{
    size_t i = 0;

    if (literal[0] == '-')
        i = 1;
    while (i < literal.length())
    {
        if (isdigit(literal[i]) == 0)
            return (-1);
        i++;
    }
    return (IS_INT);
}

int isFloat(const std::string& literal) {
    size_t i = 0;

    if (literal[0] == '-')
        i = 1;
    while (i < literal.length() - 1)
    {
        if (isdigit(literal[i]) == 0 && literal[i] != '.')
            return (-1);
        i++;
    }
    return (IS_FLOAT);
}

int isDouble(const std::string& literal) {
    size_t i = 0;

    if (literal[0] == '-')
        i = 1;
    while (i < literal.length())
    {
        if (isdigit(literal[i]) == 0 && literal[i] != '.')
            return (-1);
        i++;
    }
    return (IS_DOUBLE);
}

int checkSpecialCase(const std::string &literal)
{
    if (literal == "+inf" || literal == "-inf" || literal == "nan")
        return (1);
    if (literal == "+inff" || literal == "-inff" || literal == "nanf")
        return (1);
    return (0);
}

int checkType(const std::string &literal)
{
    int ocurs = countOcurs(literal, '.');
    if (literal.length() == 1)
        return (IS_CHAR);
    if (checkSpecialCase(literal))
        return (IS_SPECIAL);
    switch (ocurs)
    {
        case 0:
            return (isInt(literal));
        case 1:
            if (literal[literal.length() - 1] == 'F' || literal[literal.length() - 1] == 'f')
                return (isFloat(literal));
            else
                return (isDouble(literal));
        default:
            return (-1);
    }
}
