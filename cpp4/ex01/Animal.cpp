/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:49 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/25 18:22:16 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Constructor got called." << std::endl;
	this->type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal Deconstructor got called." << std::endl;
}

Animal::Animal(const Animal& cp)
{
	*this = cp;
}

Animal& Animal::operator= (const Animal& cp)
{
	if (this != &cp)
		*this = cp;
	return(*this);
}

void	Animal::makeSound(void) const
{
	std::cout << this->getType() << " is making a sound!" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
