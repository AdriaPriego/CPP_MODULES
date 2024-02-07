/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:43:53 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 23:23:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct	s_Data
{
	char	c;
}				Data;


class Serializer
{
    private:
        Serializer( void );
        Serializer operator=(const Serializer &cpy);
        Serializer(const Serializer &cpy);
        ~Serializer( void );
    public:
        static uintptr_t serialize( Data* ptr );
        static Data *deserialize( uintptr_t raw );
};

#endif
