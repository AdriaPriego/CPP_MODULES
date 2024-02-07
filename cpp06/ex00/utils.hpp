/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:34:47 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 22:37:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include <iostream>
# define IS_INT 1
# define IS_DOUBLE 2
# define IS_FLOAT 3
# define IS_CHAR 4
# define IS_SPECIAL 5

int countOcurs(const std::string literal, const char toFind);
int isInt(const std::string& literal);
int isFloat(const std::string& literal);
int isDouble(const std::string& literal);
int checkSpecialCase(const std::string &literal);
int checkType(const std::string &literal);

#endif