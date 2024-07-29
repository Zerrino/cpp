/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:49 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/27 01:53:54 by alexafer         ###   ########.fr       */
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
		this->type = cp.getType();
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << this->getType() << " is making a sound!" << std::endl;
}

Brain*	Animal::getBrain(void) const
{
	return (0);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
