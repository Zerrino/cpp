/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:25:01 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 09:51:08 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("", 0, 0)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cp)
	: AForm(cp)
{
	*this = cp;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& cp)
{
	if (this != &cp)
		*this = cp;
	return (*this);
}

void	RobotomyRequestForm::takeAction() const
{
	std::random_device ran;

	std::cout << "ZzzzzZzzzzz..." << std::endl;
	std::cout << this->_target << " you're informed that ... ";
	if (ran() % 2)
		std::cout << "you have been successfully robotomized!!" << std::endl;
	else
		std::cout << "you have NOT been successfully robotomized..." << std::endl;
}
