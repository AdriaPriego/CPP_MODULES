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
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	ferran("Ferran", 145);
	Bureaucrat	boss("Boss", 1);
	Intern		becari;
	AForm		*form = NULL;

	std::cout << std::endl << RED << "Bad Type" << END << std::endl;
	try
	{
		form = becari.makeForm("pp", "Bender");
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl << GREEN << "Correct Type" << END << std::endl;
	try
	{
		form = becari.makeForm("robotomy", "Pami");

		std::cout << ferran << std::endl;
		std::cout << boss << std::endl;
		std::cout << *form << std::endl;

		ferran.signForm(*form);
		ferran.executeForm(*form);

		std::cout << *form << std::endl;

		boss.signForm(*form);
		boss.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	delete form;
	return (0);
}
