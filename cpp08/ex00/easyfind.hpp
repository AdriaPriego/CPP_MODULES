/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:37:58 by codespace         #+#    #+#             */
/*   Updated: 2024/02/09 17:51:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

template <typename T>
void easyfind(T cont, int find)
{
    if (std::find(cont.begin(), cont.end(), find) == cont.end())
        throw std::invalid_argument("Not found");
}