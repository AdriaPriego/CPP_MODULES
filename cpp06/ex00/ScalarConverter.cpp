/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:57:30 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 17:39:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream> // Para atof
#include <cstdlib>
#include <climits>
#include <cfloat>

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

void transformChar(const char c)
{
    if (c < 33 || c > 126)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << c << "'" << std::endl;
    std::cout << "Int: " << (int)c << std::endl;
    std::cout << "Float: " << (float)c << ".0f" << std::endl;
    std::cout << "Double: " << c << ".0" << std::endl;
}

bool test_int(const std::string literal)
{
    long res = 0;
    size_t i = 0;
    int sign = 1;

    if (literal[0] == '-')
    {
        sign = -1;
        i = 1;
    }
    for (; i < literal.length(); i++)
    {
        if (isdigit(literal[i]) == 0)
            return (false);
        res *= 10;
        res += literal[i] - '0';
        if (res * sign > INT_MAX || res * sign < INT_MIN)
            return (false);
    }
    return (true);
}

void transformInt(std::string literal)
{
    int numint = std::atoi(literal.c_str());
    double numdouble = std::atof(literal.c_str());
    float numfloat = std::atof(literal.c_str());

    if (numint < 33 || numint > 126)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << (char)numint << "'" << std::endl;
    if (test_int(literal))
        std::cout << "Int: " << numint << std::endl;
    else
        std::cout << "Int: Non displayable" << std::endl;
    std::cout << "Float: " << numfloat << "f" << std::endl;
    std::cout << "Double: " << numdouble << std::endl;
}

void transformFloat(std::string literal)
{
    int numint = std::atof(literal.c_str());
    double numdouble = std::atof(literal.c_str());
    float numfloat = std::atof(literal.c_str());

    std::cout << "FLOAT" << std::endl;
    if (numint < 33 || numint > 126)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << (char)numint << "'" << std::endl;
    if (numint > INT_MAX || numint < INT_MIN || (numint == INT_MIN && literal.find_first_of('.', 0) > 11))
        std::cout << "Int: Non displayable" << std::endl;
    else
        std::cout << "Int: " << (int)numint << std::endl;
    std::cout << "Float: " << numfloat << "f" << std::endl;
    std::cout << "Double: " << numdouble << std::endl;
}

void transformDouble(std::string literal)
{
    int numint = std::atof(literal.c_str());
    double numdouble = std::atof(literal.c_str());
    float numfloat = std::atof(literal.c_str());

    std::cout << "FLOAT" << std::endl;
    if (numint < 33 || numint > 126)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << (char)numint << "'" << std::endl;
    if (numint > INT_MAX || numint < INT_MIN || (numint == INT_MIN && literal.find_first_of('.', 0) > 11))
        std::cout << "Int: Non displayable" << std::endl;
    else
        std::cout << "Int: " << (int)numint << std::endl;
    std::cout << "Float: " << numfloat << "f" << std::endl;
    std::cout << "Double: " << numdouble << std::endl;
}

void caseSpecial(std::string literal)
{
    std::cout << "Char: Non displayable" << std::endl;
    std::cout << "Int: Non displayable" << std::endl;
    if (literal == "+inf")
    {
        std::cout << "Float: " << literal << "f" << std::endl;
        std::cout << "Double: " << literal << std::endl;
    }
    else if (literal == "+inff")
    {
        std::cout << "Float: " << literal << std::endl;
        std::cout << "Double: +inf" << std::endl;
    }
    else if (literal == "-inf")
    {
        std::cout << "Float: " << literal << "f" << std::endl;
        std::cout << "Double: " << literal << std::endl;
    }
    else if (literal == "-inff")
    {
        std::cout << "Float: " << literal << std::endl;
        std::cout << "Double: -inf" << std::endl;
    }
    else if (literal == "nan")
    {
        std::cout << "Float: " << literal << "f" << std::endl;
        std::cout << "Double: " << literal << std::endl;
    }
    else if (literal == "nanf")
    {
        std::cout << "Float: " << literal << std::endl;
        std::cout << "Double: nanf" << std::endl;
    }
}

void ScalarConverter::convert(std::string literal)
{
    switch (checkType(literal))
    {
        case IS_INT:
            transformInt(literal);
            break;
        case IS_FLOAT:
            transformFloat(literal);
            break;
        case IS_DOUBLE:
            transformDouble(literal);
            break;
        case IS_CHAR:
            transformChar(literal[0]);
            break;
        case IS_SPECIAL:
            caseSpecial(literal);
        break;
        default:
            std::cout << "Bad argument" << std::endl;
            break;
    }
}
