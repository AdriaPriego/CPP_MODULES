/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriego- <apriego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:43:07 by apriego-          #+#    #+#             */
/*   Updated: 2024/02/02 18:12:04 by apriego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ): _name("Default"), _grade_sign(42), _grade_exe(42)
{
	_is_signed = false;
	std::cout << "Destructor" << std::endl;
}

Form::Form( std::string name, int grade_sign, int grade_exe):
	_name(name), _grade_sign(grade_sign), _grade_exe(grade_exe)
{
	if (grade_exe > 150 || grade_sign > 150)
		throw Form::GradeTooLowException();
	else if (grade_exe < 1 || grade_sign < 1)
		throw Form::GradeTooHighException();
	_is_signed = false;
}

Form::Form( Form &cpy ): _name(cpy._name), _grade_sign(cpy._grade_sign), _grade_exe(cpy._grade_exe)
{
	if (cpy._grade_exe > 150 || cpy._grade_sign > 150)
		throw Form::GradeTooLowException();
	else if (cpy._grade_exe < 0 || cpy._grade_sign < 0)
		throw Form::GradeTooHighException();
	_is_signed = cpy._is_signed;
}

Form &Form::operator=(Form &cpy )
{
	_is_signed = cpy._is_signed;
	return (*this);
}

int	Form::getGradeSign( void ) const
{
	return (_grade_sign);
}
int	Form::getGradeExe( void ) const
{
	return (_grade_exe);
}
bool Form::getSigned( void ) const
{
	return (_is_signed);
}
std::string Form::getName( void ) const
{
	return (_name);
}

void Form::beSigned( const Bureaucrat &bure )
{
	if (bure.getGrade() <= _grade_sign)
		this->_is_signed = true;
	else
	{
		this->_is_signed = false;
		throw Form::GradeTooLowException();
	}
}

Form::~Form( void )
{
	std::cout << "Destructor" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	if (form.getSigned())
		return ( out << form.getName() << " is signed " << " :" << std::endl 
			<< "Grade to sign: " << form.getGradeSign() << std::endl << "Grade to exe: " 
			<< form.getGradeExe() << std::endl );
	return ( out << form.getName() << " is not signed " << " :" << std::endl 
		<< "Grade to sign: " << form.getGradeSign() << std::endl << "Grade to exe: " 
		<< form.getGradeExe() << std::endl );
}


const char *Form::GradeTooHighException::what( void ) const throw()
{
	return ("Grade Too High [1 - 150]");
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade Too Low[1 - 150]");
}
