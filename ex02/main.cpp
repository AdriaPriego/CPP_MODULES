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
#include "Colors.hpp"

int	main(void)
{
	try
	{
		AForm *generic = new PresidentialPardonForm();
		Bureaucrat test("PETER", 1);

		test.signForm(*generic);
		test.executeForm(*generic);
		delete generic;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}