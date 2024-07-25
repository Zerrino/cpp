/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:25:17 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/25 18:25:17 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
}

Brain::~Brain()
{
}

Brain::Brain(const Brain& cp)
{
	*this = cp;
}

Brain& Brain::operator= (const Brain& cp)
{
	if (this != &cp)
		*this = cp;
	return(*this);
}
