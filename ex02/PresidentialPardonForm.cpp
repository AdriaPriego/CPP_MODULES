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

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ):
AForm("PresidentialPardonForm", 25, 5), _target("DEF")
{
    std::cout << "Default" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ):
AForm("PresidentialPardonForm", 25, 5),  _target(target)
{
    std::cout << "Init Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm &cpy ):
AForm(cpy), _target(cpy.getTarget())
{
    std::cout << "Copy Constructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm &cpy )
{
    _target = cpy.getTarget();
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    std::cout << "Destructor Constructor" << std::endl;
}

std::string PresidentialPardonForm::getTarget( void )
{
    return (_target);
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
    if (!getSigned())
        throw NotSigned();
    if (executor.getGrade() <= getGradeExe())
        std::cout << "Informs that " << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    else
        throw GradeTooLowException();
}
