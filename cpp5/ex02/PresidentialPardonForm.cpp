/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:25:01 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 09:35:21 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("", 0, 0)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cp)
	: AForm(cp)
{
	*this = cp;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& cp)
{
	if (this != &cp)
		*this = cp;
	return (*this);
}

void	PresidentialPardonForm::takeAction() const
{
	std::cout << this->_target << " you're informed that you have been pardoned by Zaphod Beeblebrox." << std::endl;
}
