/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:50 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/25 18:23:07 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Constructor got called." << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Deconstructor got called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cp)
{
	*this = cp;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& cp)
{
	if (this != &cp)
		*this = cp;
	return(*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->getType() << " is making a sound!" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
