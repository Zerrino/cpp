/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:07:53 by alexafer          #+#    #+#             */
/*   Updated: 2024/08/09 15:07:53 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& cp)
{
	*this = cp;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& cp)
{
	if (this != &cp)
		*this = cp;
	return (*this);
}
