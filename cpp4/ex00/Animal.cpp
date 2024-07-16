/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:49 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/16 14:25:32 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
}

Animal::~Animal()
{
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

void	Animal::makeSound(void)
{
	std::cout << "Animal is making a sound!" << std::endl;
}
