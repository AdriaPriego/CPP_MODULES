/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:57:30 by codespace         #+#    #+#             */
/*   Updated: 2024/02/08 14:13:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
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

void transformChar(const char c)
{
    if (c < 33 || c > 126)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << c << "'" << std::endl;
    std::cout << "Int: " << (int)c << std::endl;
    std::cout << "Float: " << (float)c << ".0f" << std::endl;
    std::cout << "Double: " << (double)c << ".0" << std::endl;
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
    double numdouble = static_cast<double>(numint);
    float numfloat = static_cast<float>(numint);
    char c = static_cast<char>(numint);

    if(countOcurs(literal, '-') == 0 && numint == -1)
        std::cout << "Int overflow" << std::endl;
    else if (literal.length() - countOcurs(literal, '0') > 2 && numint == 0)
    {
        std::cout << "Int underflow" << std::endl;
    }
    else
    {
        if (!isprint(numint))
            std::cout << "Char: Non displayable" << std::endl;
        else
            std::cout << "Char: '" << c << "'" << std::endl;
        if (test_int(literal))
            std::cout << "Int: " << numint << std::endl;
        else
            std::cout << "Int: Non displayable" << std::endl;
        std::cout << "Float: " << numfloat << "f" << std::endl;
        std::cout << "Double: " << numdouble << std::endl;
    }
}

void transformFloat(std::string literal)
{
    float numfloat = std::atof(literal.c_str());
    double numdouble = static_cast<double>(numfloat);
    int numint = static_cast<int>(numfloat);
    char c = static_cast<char>(numfloat);

    if (!isascii(numfloat))
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << c << "'" << std::endl;
    if (numint > INT_MAX || numint < INT_MIN || (numint == INT_MIN && literal.find_first_of('.', 0) > 11))
        std::cout << "Int: Non displayable" << std::endl;
    else
        std::cout << "Int: " << numint << std::endl;
    std::cout << "Float: " << numfloat << "f" << std::endl;
    std::cout << "Double: " << numdouble << std::endl;
}

void transformDouble(std::string literal)
{
    double numdouble = std::atof(literal.c_str());
    int numint = static_cast<int>(numdouble);
    float numfloat = static_cast<float>(numdouble);
    char c = static_cast<char>(numdouble);

    if (!isascii(numdouble))
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << c << "'" << std::endl;
    if (numint > INT_MAX || numint < INT_MIN || (numint == INT_MIN && literal.find_first_of('.', 0) > 11))
        std::cout << "Int: Non displayable" << std::endl;
    else
        std::cout << "Int: " << numint << std::endl;
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
        std::cout << "Double: nan" << std::endl;
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
