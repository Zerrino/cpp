/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:50 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/25 17:27:16 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
}

WrongCat::WrongCat(const WrongCat& cp)
{
	*this = cp;
}

WrongCat& WrongCat::operator= (const WrongCat& cp)
{
	if (this != &cp)
		*this = cp;
	return(*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->getType() << " says : Miaoouuuuuuuuuu" << std::endl;
}

