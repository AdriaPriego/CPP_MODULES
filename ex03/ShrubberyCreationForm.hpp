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

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm &cpy );
		ShrubberyCreationForm &operator=( ShrubberyCreationForm &cpy );
		~ShrubberyCreationForm( void );
		std::string getTarget( void );
		void execute( Bureaucrat const & executor ) const;
};

#endif	