/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 10:50:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
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
std::vector<std::string> split(const std::string& s, char delimiter);
std::vector<t_exchange> parseBD(std::vector<std::string> fileVector);
t_exchange parseLine(std::string line);
void doExchange(std::vector<t_exchange> dataBD, std::vector<std::string> fileVector);
