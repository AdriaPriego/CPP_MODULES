/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Forms.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriego- <apriego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:43:12 by apriego-          #+#    #+#             */
/*   Updated: 2024/02/02 18:14:27 by apriego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMS_HPP
# define FORMS_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Forms
{
	private:
		const std::string _name;
		bool	_is_signed;
		const int	_grade_sign;
		const int	_grade_exe;
	public:
		Forms( void );
		Forms( std::string name, int grade_sign, int grade_exe);
		Forms( Forms &cpy );
		Forms &operator=(Forms &cpy );
		~Forms( void );
		int	getGradeSign( void ) const;
		int	getGradeExe( void ) const;
		bool getSigned( void ) const;
		std::string getName( void ) const;
		void beSigned( Bureaucrat const bure );
		void Forms::signForm( Forms  );
		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

std::ostream &		operator<<(std::ostream &out, const Forms &bur);

#endif	