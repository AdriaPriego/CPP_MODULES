/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:29:47 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 23:30:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
 
class Base
{
	public:
		virtual ~Base( void ) {};
};

class A: public Base {};

class B: public Base {};

class C: public Base {};

#endif