/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriego- <apriego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:54:39 by apriego-          #+#    #+#             */
/*   Updated: 2024/02/02 18:00:57 by apriego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ): _name("Default")
{
	_grade = 42;
	std::cout << "Default Constructor" << std::endl;
}
Bureaucrat::Bureaucrat( const Bureaucrat &cpy )
{
	*this = cpy;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &cpy )
{
	_grade = cpy._grade;
	return (*this);
}

Bureaucrat::Bureaucrat( std::string name, int grade ): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
	std::cout << "New Bureaucrat Created" << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Deleted Bureaucrat" << std::endl;
}

std::string Bureaucrat::getName( void ) const
{
	return (_name);
}
int Bureaucrat::getGrade( void ) const
{
	return (_grade);
}
void Bureaucrat::incrementGrade( void )
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}
void Bureaucrat::decrementGrade( void )
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bur)
{
	return ( out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl);
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade Too High [1 - 150]");
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade Too Low[1 - 150]");
}
