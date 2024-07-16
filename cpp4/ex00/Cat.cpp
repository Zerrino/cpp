/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:49 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/16 14:30:03 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	type("Cat")
{
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

void	Cat::makeSound(void)
{
	std::cout << "Miaoouuuuuuuuuu" << std::endl;
}
