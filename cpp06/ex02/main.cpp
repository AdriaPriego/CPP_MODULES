/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:29:48 by codespace         #+#    #+#             */
/*   Updated: 2024/02/07 23:47:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base * generate( void )
{
    srand(time(NULL));
    switch (rand() % 3)
    {
        case 0:
            return (new A());
            break;
        case 1:
            return (new B());
            break;
        case 2:
            return (new C());
            break;
    }
    return (new Base());
}

void identify( Base* p )
{
    if (dynamic_cast<A*>(p))
        std::cout << "Object pointed to by p is of type A." << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Object pointed to by p is of type B." << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Object pointed to by p is of type C." << std::endl;
    else
        std::cout << "Object pointed to by p is of an unknown type." << std::endl;
}

void identify( Base& p )
{
	try
	{
		A& a = dynamic_cast< A& >( p );
		( void )a;
		std::cout << "Object refereced to by p is of type A" << std::endl;
		return ;
	}
	catch ( std::exception& e ) {}
	try
	{
		B& b = dynamic_cast< B& >( p );
		( void )b;
		std::cout << "Object refereced to by p is of type B" << std::endl;
		return ;
	}
	catch ( std::exception& e ) {}
	try
	{
		C& c = dynamic_cast< C& >( p );
		( void )c;
		std::cout << "Object refereced to by p is of type C" << std::endl;
		return ;
	}
	catch ( std::exception& e ) {}
    std::cout << "Object refereced to by p is of an unknown type." << std::endl;
}

int main(void)
{
    Base	*base;

	base = generate();
	identify( base );
	identify( *base );
    delete base;
	return ( 0 );
}