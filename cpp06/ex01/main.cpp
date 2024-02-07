/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:00:01 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 23:25:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
int main( void )
{
    Data testing;
    
    std::cout << "Ptr no serializer " << &testing << std::endl;
    uintptr_t hola = Serializer::serialize(&testing);
    std::cout << "Uintptr_t  " << hola << std::endl;
    std::cout << "Ptr serializer " << Serializer::deserialize(hola) << std::endl;
    
}