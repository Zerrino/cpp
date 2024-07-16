/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:50 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/16 14:18:50 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal::WrongAnimal(const WrongAnimal& cp)
{
	*this = cp;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& cp)
{
	if (this != &cp)
		*this = cp;
	return(*this);
}
