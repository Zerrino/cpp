/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:49 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/25 17:24:14 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
}

Cat::~Cat()
{
}

Cat::Cat(const Cat& cp)
{
	*this = cp;
}

Cat& Cat::operator= (const Cat& cp)
{
	if (this != &cp)
		*this = cp;
	return(*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << " says : Miaoouuuuuuuuuu" << std::endl;
}
