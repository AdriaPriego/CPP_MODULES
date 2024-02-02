/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriego- <apriego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:05:57 by apriego-          #+#    #+#             */
/*   Updated: 2024/01/29 19:17:18 by apriego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"

int main( void )
{
	std::cout << std::endl << GREEN << "1 TEST: Init imposible" << END << std::endl << std::endl;
	try
	{
		Bureaucrat test("PETER", 234);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << GREEN << "2 TEST: Increment imposible" << END << std::endl << std::endl;
	try
	{
		Bureaucrat test("PETER", 1);

		std::cout << "Pre Grade: " << test.getGrade() << std::endl;
		test.incrementGrade();
		std::cout << "Grade: " << test.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << GREEN << "3 TEST: Increment posible" << END << std::endl << std::endl;
	try
	{
		Bureaucrat test("PETER", 2);

		std::cout << "Pre Grade: " << test.getGrade() << std::endl;
		test.incrementGrade();
		std::cout << "Grade: " << test.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << GREEN << "4 TEST: Decrement imposible" << END << std::endl << std::endl;
	try
	{
		Bureaucrat test("PETER", 150);

		std::cout << "Pre Grade: " << test.getGrade() << std::endl;
		test.decrementGrade();
		std::cout << "Grade: " << test.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << GREEN << "5 TEST: Increment posible" << END << std::endl << std::endl;
	try
	{
		Bureaucrat test("PETER", 149);

		std::cout << "Pre Grade: " << test.getGrade() << std::endl;
		test.decrementGrade();
		std::cout << "Grade: " << test.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << GREEN << "6 TEST: All okey" << END << std::endl << std::endl;
	try
	{
		Bureaucrat test("PETER", 125);

		std::cout << test;
		test.decrementGrade();
		std::cout << test;
		test.decrementGrade();
		std::cout << test;
		test.incrementGrade();
		std::cout << test;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}