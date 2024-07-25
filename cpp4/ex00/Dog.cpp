/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:49 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/25 17:24:24 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
		this->type = "Dog";
}

Dog::~Dog()
{
}

Dog::Dog(const Dog& cp)
{
	*this = cp;
}

Dog& Dog::operator= (const Dog& cp)
{
	if (this != &cp)
		*this = cp;
	return(*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << " says : Woof woof!" << std::endl;
}
