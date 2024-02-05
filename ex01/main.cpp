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
#include "Form.hpp"
#include "Colors.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	ferran("Ferran", 140);
		Bureaucrat	boss("Boss", 1);
		Form		basicForm("Basic stuff", 140, 150);
		Form		basicForm2(basicForm);
		Form		advancedForm("Advanced stuff", 10, 1);
		
		std::cout << ferran << std::endl;
		std::cout << boss << std::endl;
		std::cout << basicForm << std::endl;
		std::cout << basicForm2 << std::endl;
		std::cout << advancedForm << std::endl;
		
		ferran.signForm(basicForm);
		boss.signForm(basicForm2);
		ferran.signForm(advancedForm);

		boss.signForm(advancedForm);
		std::cout << basicForm << std::endl;
		std::cout << basicForm2 << std::endl;
		std::cout << advancedForm << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}