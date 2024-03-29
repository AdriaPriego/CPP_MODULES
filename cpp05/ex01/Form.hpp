/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriego- <apriego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:43:12 by apriego-          #+#    #+#             */
/*   Updated: 2024/02/02 18:14:27 by apriego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool	_is_signed;
		const int	_grade_sign;
		const int	_grade_exe;
	public:
		Form( void );
		Form( std::string name, int grade_sign, int grade_exe);
		Form( Form &cpy );
		Form &operator=( Form &cpy );
		~Form( void );
		int	getGradeSign( void ) const;
		int	getGradeExe( void ) const;
		bool getSigned( void ) const;
		std::string getName( void ) const;
		void beSigned( const Bureaucrat &bure );
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

std::ostream &		operator<<(std::ostream &out, const Form &bur);

#endif	