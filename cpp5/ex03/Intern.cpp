/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:25:28 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 11:56:32 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& cp)
{
	*this = cp;
}

Intern& Intern::operator= (const Intern& cp)
{
	if (this != &cp)
		*this = cp;
	return (*this);
}

const char* Intern::NoFormException::what() const throw ()
{
	return ("This form doesn't exist, such a lame intern!");
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	std::string ForName[] =
	{"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};

	for (size_t i = 0; i < 3; i++)
	{
		if (ForName[i] == form)
		{
			switch (i)
			{
			case 0:
				return (new PresidentialPardonForm(target));
			case 1:
				return (new RobotomyRequestForm(target));
			case 2:
				return (new ShrubberyCreationForm(target));
			default:
				throw NoFormException();
			}
		}
	}
	throw NoFormException();
	return (0);
}
