/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:58:33 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 17:29:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            if (token[0] == '*')
                st.push(num2 * num1);
            if (token[0] == '+')
                st.push(num2 + num1);
            if (token[0] == '-')
                st.push(num2 - num1);
            if (token[0] == '/')
                st.push(num2 / num1);
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