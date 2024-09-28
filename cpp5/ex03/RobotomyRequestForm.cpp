/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:25:01 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/25 17:02:10 by marvin           ###   ########.fr       */
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
	srand(time(0));
	int randomNumber = rand();

	std::cout << "ZzzzzZzzzzz..." << std::endl;
	std::cout << this->_target << " you're informed that ... ";
	if (randomNumber % 2)
		std::cout << "you have been successfully robotomized!!" << std::endl;
	else
		std::cout << "you have NOT been successfully robotomized..." << std::endl;
}
