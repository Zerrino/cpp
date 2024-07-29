/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:02:41 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/28 02:03:28 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(const Ice& cp)
	: AMateria("ice")
{
	*this = cp;
}

Ice& Ice::operator= (const Ice& cp)
{
	if (this != &cp)
		this->type = cp.type;
	return (*this);
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
