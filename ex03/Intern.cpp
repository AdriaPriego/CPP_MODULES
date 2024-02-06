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

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void )
{
    std::cout << "Default const" << std::endl;
}

Intern::Intern( Intern &cpy )
{
    std::cout << "Copy const" << std::endl;
    *this = cpy;
}

Intern Intern::operator=( Intern &cpy )
{
    std::cout << "Operator =" << std::endl;
    (void)cpy;
    return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
    int type = -1;
    std::string formstype[3] = {
        "robotomy",
        "presidential",
        "shrubbery"
    };

    for (int i = 0; i < 3 && type == -1; i++)
    {
        if (formstype[i] == formName)
            type = i;
    }

    switch (type)
    {
    case 0:
        return (new RobotomyRequestForm(formTarget));
    case 1:
        return (new PresidentialPardonForm(formTarget));
    case 2:
        return (new ShrubberyCreationForm(formTarget));
    default:
        throw BadFormType();
        break;
    }
}

const char *Intern::BadFormType::what( void ) const throw()
{
    return ("Bad form type only: robotomy, presidential, shrubbery");
}

Intern::~Intern( void )
{
    std::cout << "Destructor Intern" << std::endl;
}
