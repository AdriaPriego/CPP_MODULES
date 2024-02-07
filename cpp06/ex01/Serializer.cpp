/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:43:50 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 23:19:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void )
{
    std::cout << "Default Const" << std::endl;
}

Serializer Serializer::operator=(const Serializer &cpy)
{
    (void)cpy;
    return (*this);
}

Serializer::Serializer(const Serializer &cpy)
{
    *this = cpy;
}

Serializer::~Serializer( void )
{
    std::cout << "Default Destructor" << std::endl;
}

uintptr_t	Serializer::serialize( Data *ptr )
{
	return ( reinterpret_cast< uintptr_t >( ptr ) );
}

Data	*Serializer::deserialize( uintptr_t raw )
{
	return ( reinterpret_cast< Data *>( raw ) );
}
