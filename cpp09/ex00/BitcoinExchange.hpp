/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/19 13:14:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <ctime>
#include <sstream>
#include <climits>
#include <cstdlib>

typedef struct s_exchange
{
    struct tm tm;
    double eRate;
}           t_exchange;

int dayDifference(const struct tm &date1, const struct tm &date2);
std::list<std::string> split(const std::string& s, char delimiter);
std::list<t_exchange> parseBD(std::list<std::string> fileList);
t_exchange parseLine(std::string line);
void doExchange(std::list<t_exchange> dataBD, std::list<std::string> fileList);
