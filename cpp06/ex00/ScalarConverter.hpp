/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:57:28 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 22:35:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include "utils.hpp"
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