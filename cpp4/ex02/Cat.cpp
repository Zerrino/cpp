/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:49 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/27 01:48:54 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_brain = new Brain();
	std::cout << "Cat Constructor got called." << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Deconstructor got called." << std::endl;
}

Cat::Cat(Cat & cp)
{
	std::cout << "Cat copy got called." << std::endl;
	this->_brain = new Brain(*(cp.getBrain()));
	this->type = cp.getType();
}

Cat&		Cat::operator=(const Cat& cp)
{
	this->type = cp.type;
	if (this->_brain)
		delete (this->_brain);
	this->_brain = new Brain(*(cp.getBrain()));
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << " says : Miaoouuuuuuuuuu" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (this->_brain);
}
