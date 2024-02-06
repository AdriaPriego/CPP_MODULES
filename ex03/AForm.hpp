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

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool	_is_signed;
		const int	_grade_sign;
		const int	_grade_exe;
	public:
		AForm( void );
		AForm( std::string name, int grade_sign, int grade_exe);
		AForm( AForm &cpy );
		AForm &operator=( AForm &cpy );
		virtual ~AForm( void ) = 0;
		int	getGradeSign( void ) const;
		int	getGradeExe( void ) const;
		bool getSigned( void ) const;
		std::string getName( void ) const;
		void beSigned( const Bureaucrat &bure );
		virtual void execute( Bureaucrat const & executor ) const = 0;
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
		class NotSigned : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

std::ostream &		operator<<(std::ostream &out, const AForm &bur);

#endif	