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

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm( void ):
AForm("RobotomyRequestForm", 72, 45), _target("DEF")
{
    std::cout << "Default" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ):
AForm("RobotomyRequestForm", 72, 45),  _target(target)
{
    std::cout << "Init Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm &cpy ):
AForm(cpy), _target(cpy.getTarget())
{
    std::cout << "Copy Constructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm &cpy )
{
    _target = cpy.getTarget();
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    std::cout << "Destructor Constructor" << std::endl;
}

std::string RobotomyRequestForm::getTarget( void )
{
    return (_target);
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
    if (!getSigned())
        throw NotSigned();
    std::cout << "zxcbnxcczvx........" << std::endl;
    if (executor.getGrade() <= getGradeExe())
    {
        srand(time(NULL));
        if (rand() % 2)
            std::cout << "Informs that " << _target << " has been robotomized." << std::endl;
        else
            std::cout << "Informs that robotomy failed." << std::endl;
    }
    else
        throw GradeTooLowException();
}
