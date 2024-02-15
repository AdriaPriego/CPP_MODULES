/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/15 14:35:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime>
#include <climits>
#include <iostream>
#include <cstdlib>

typedef struct s_exchange
{
    struct tm tm;
    double eRate;
}           t_exchange;

int dayDifference(const struct tm &date1, const struct tm &date2)
{
    int date1Acum = date1.tm_year * 365 + date1.tm_mon * 30 + date1.tm_mday;
    int date2Acum = date2.tm_year * 365 + date2.tm_mon * 30 + date2.tm_mday;
    return (date1Acum - date2Acum);
}