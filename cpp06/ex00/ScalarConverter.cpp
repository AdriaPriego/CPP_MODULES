/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:57:30 by codespace         #+#    #+#             */
/*   Updated: 2024/02/06 13:03:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream> // Para atof
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter(void)
{
    std::cout << "Default Constructor" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter &cpy)
{
    std::cout << "Copy Constructor" << std::endl;
    *this = cpy;
}

ScalarConverter ScalarConverter::operator=(ScalarConverter &cpy)
{
    (void)cpy;
    std::cout << "Copy Operator" << std::endl;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Default Destructor" << std::endl;    
}

void isChar(char c)
{
    std::cout << "Char: '" << c << "'" << std::endl;
    std::cout << "Int: " << (int)c << std::endl;
    std::cout << "Float: " << (float)c << std::endl;
    std::cout << "Double: " << (double)c << std::endl;
}

int countOcurs(std::string literal, char toFind)
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

    while (i < literal.length())
    {
        if (isdigit(literal[i]) == 0 && literal[i] != '.')
            return (-1);
        i++;
    }
    return (IS_DOUBLE);
}

int checkType(const std::string& literal)
{
    int ocurs = countOcurs(literal, '.');

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

void ScalarConverter::convert(std::string literal)
{
    if (literal.length() == 1)
        isChar(literal[0]);
    std::cout << "TYPE: " << checkType(literal) << std::endl;
}
