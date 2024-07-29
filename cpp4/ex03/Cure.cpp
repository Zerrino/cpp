/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:02:41 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/28 02:00:46 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure")
{

}

Cure::~Cure()
{
}

Cure::Cure(const Cure& cp)
	: AMateria("cure")
{
	*this = cp;
}

Cure& Cure::operator= (const Cure& cp)
{
	if (this != &cp)
		this->type = cp.type;
	return (*this);
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<"’s wounds *" << std::endl;
}
