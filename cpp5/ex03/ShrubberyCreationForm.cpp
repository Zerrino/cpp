/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:25:01 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 10:11:01 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("", 0, 0)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cp)
	: AForm(cp)
{
	*this = cp;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& cp)
{
	if (this != &cp)
		*this = cp;
	return (*this);
}

const char* ShrubberyCreationForm::CantOpenFile::what() const throw ()
{
	return ("Cannot open the file!");
}

void	ShrubberyCreationForm::takeAction() const
{
	std::string	path;
	std::string tree =
"    oxoxoo    ooxoo\n"
"  ooxoxo oo  oxoxooo\n"
" oooo xxoxoo ooo ooox\n"
" oxo o oxoxo  xoxxoxo\n"
"  oxo xooxoooo o ooo\n"
"    ooo\\oo\\  /o/o\n"
"        \\  \\/ /\n"
"         |   /\n"
"         |  |\n"
"         | D|\n"
"         |  |\n"
"         |  |\n"
"  ______/____\\____";

	path = "./" + this->_target + "_shrubbery";
	std::ofstream file(path);
	if (!file.is_open())
		throw CantOpenFile();
	file << tree << std::endl;
	file.close();
}
