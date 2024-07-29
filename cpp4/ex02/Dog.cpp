/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:49 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/27 01:48:38 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_brain = new Brain();
	std::cout << "Dog Constructor got called." << std::endl;
	this->type = "Dog";
	new Brain();
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Deconstructor got called." << std::endl;
}

Dog::Dog(Dog & cp)
{
	std::cout << "Dog copy got called." << std::endl;
	this->_brain = new Brain(*(cp.getBrain()));
	this->type = cp.getType();
}

Dog&		Dog::operator=(const Dog& cp)
{
	this->type = cp.type;
	if (this->_brain)
		delete (this->_brain);
	this->_brain = new Brain(*(cp.getBrain()));
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << " says : Woof woof!" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (this->_brain);
}
