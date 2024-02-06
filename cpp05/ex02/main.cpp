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

int	main(void)
{
	Bureaucrat	ferran("Ferran", 145);
	Bureaucrat	boss("Boss", 1);
	AForm		*shrubberyForm = new ShrubberyCreationForm("Joselito");
	AForm		*robotomyForm = new RobotomyRequestForm("Pandu");
	AForm		*pardonForm = new PresidentialPardonForm("Hannibal");

	try
	{
		std::cout << ferran << std::endl;
		std::cout << boss << std::endl;
		std::cout << *shrubberyForm << std::endl;
		std::cout << *robotomyForm << std::endl;
		std::cout << *pardonForm << std::endl;

		ferran.signForm(*shrubberyForm);
		ferran.executeForm(*shrubberyForm);

		std::cout << *shrubberyForm << std::endl;

		boss.executeForm(*shrubberyForm);

		std::cout << *robotomyForm << std::endl;
		ferran.signForm(*robotomyForm);
		boss.signForm(*robotomyForm);
		boss.executeForm(*robotomyForm);

		ferran.signForm(*pardonForm);
		ferran.executeForm(*pardonForm);
		boss.executeForm(*pardonForm);
		boss.signForm(*pardonForm);
		boss.executeForm(*pardonForm);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	delete shrubberyForm;
	delete robotomyForm;
	delete pardonForm;
	return (0);
}