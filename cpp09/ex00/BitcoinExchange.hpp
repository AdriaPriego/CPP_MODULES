/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:05:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/14 18:13:12 by codespace        ###   ########.fr       */
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
    double qtt;
}           t_exchange;

bool test_int(const std::string literal);