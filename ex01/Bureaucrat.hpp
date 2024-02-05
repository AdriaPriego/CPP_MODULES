/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apriego- <apriego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:46:09 by apriego-          #+#    #+#             */
/*   Updated: 2024/01/30 13:17:47 by apriego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;
	public:
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &cpy );
		Bureaucrat( std::string name, int grade );
		Bureaucrat &operator=( const Bureaucrat &cpy );
		~Bureaucrat( void );
		std::string getName( void ) const;
		int getGrade( void ) const;
		void signForm( Form & form );
		void incrementGrade( void );
		void decrementGrade( void );
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

std::ostream &		operator<<(std::ostream &out, const Bureaucrat &bur);

#endif