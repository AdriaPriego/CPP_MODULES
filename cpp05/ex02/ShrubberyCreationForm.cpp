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

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ):
AForm("ShrubberyCreationForm", 145, 137), _target("DEF")
{
    std::cout << "Default" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ):
AForm("ShrubberyCreationForm", 145, 137),  _target(target)
{
    std::cout << "Init Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm &cpy ):
AForm(cpy), _target(cpy.getTarget())
{
    std::cout << "Copy Constructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm &cpy )
{
    _target = cpy.getTarget();
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
    std::cout << "Destructor Shrubbery" << std::endl;
}

std::string ShrubberyCreationForm::getTarget( void )
{
    return (_target);
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
    if (!getSigned())
        throw NotSigned();
    if (executor.getGrade() <= getGradeExe())
    {
        std::string exte = "_shrubbery";
        std::string orig = _target + exte;
        const char *name = orig.c_str();
        std::ofstream MyFile;
        MyFile.open(name);
        if (MyFile.fail() == true)
        {
            std::cerr << "Error opening file." << std::endl;
        }
        else
        {
            MyFile << "    oxoxoo    ooxoo" << std::endl;
            MyFile << "  ooxoxo oo  oxoxooo" << std::endl;
            MyFile << " oooo xxoxoo ooo ooox" << std::endl;
            MyFile << " oooo xxoxoo ooo ooox" << std::endl;
            MyFile << " oxo o oxoxo  xoxxoxo" << std::endl;
            MyFile << "  oxo xooxoooo o ooo" << std::endl;
            MyFile << "    ooo\\oo\\  /o/o" << std::endl;
            MyFile << "        \\  \\/ /" << std::endl;
            MyFile << "         |   /" << std::endl;
            MyFile << "         |  |" << std::endl;
            MyFile << "         | D|" << std::endl;
            MyFile << "         |  |" << std::endl;
            MyFile << "         |  |" << std::endl;
            MyFile << "         |  |" << std::endl;
            MyFile << "  ______/____\\____" << std::endl;
            MyFile.close();
        }
    }
    else
        throw GradeTooLowException();
}
