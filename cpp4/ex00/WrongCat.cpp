/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:50 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/16 14:18:50 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
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
