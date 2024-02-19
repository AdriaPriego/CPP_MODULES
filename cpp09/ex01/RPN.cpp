/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriego- <apriego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:58:33 by codespace         #+#    #+#             */
/*   Updated: 2024/02/19 17:53:06 by apriego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int doOperation(int num1, int num2, char operation)
{
    if (operation == '*')
        return (num2 * num1);
    if (operation == '+')
        return (num2 + num1);
    if (operation == '-')
        return (num2 - num1);
    if (operation == '/')
    {
        if (num1 == 0)
            throw std::logic_error("Imposible division");
        return (num2 / num1);
    }
    return (num1);
}

int reversePolishNotation(char *str)
{
    std::stringstream ss(str);
    std::string token;
    std::stack<int> st;

    while (ss >> token)
    {
        if (token.size() != 1)
            throw std::logic_error("Error Bad Arguments");
        if (token[0] == '*' || token[0] == '+' || token[0] == '-' || token[0] == '/')
        {
            if (st.size() == 0)
                throw std::logic_error("Error Bad Arguments");
            int num1 = st.top();
            st.pop();
            if (st.size() == 0)
                throw std::logic_error("Error Bad Arguments");
            int num2 = st.top();
            st.pop();
            st.push(doOperation(num1, num2, token[0]));
        }
        else
        {
            if (!isdigit(token.c_str()[0]))
                throw std::logic_error("Error Bad Arguments");
            st.push(std::atoi(token.c_str()));
        }
    }
    if (st.size() != 1)
        throw std::logic_error("Error Bad Arguments");
    return (st.top());
}