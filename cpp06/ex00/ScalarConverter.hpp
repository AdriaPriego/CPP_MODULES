/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:57:28 by codespace         #+#    #+#             */
/*   Updated: 2024/02/06 12:13:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# define IS_INT 1
# define IS_DOUBLE 2
# define IS_FLOAT 3

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter &cpy);
        ScalarConverter operator=(ScalarConverter &cpy);
        ~ScalarConverter();
    public:
        static void convert(std::string literal);
};

#endif