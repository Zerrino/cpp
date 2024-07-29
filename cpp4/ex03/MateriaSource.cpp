/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:03:13 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/28 02:38:02 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	: _size(0)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		this->_materia[i] = NULL;
		i++;
	}
}

MateriaSource::~MateriaSource()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		delete this->_materia[i];
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource& cp)
{
	*this = cp;
}

MateriaSource& MateriaSource::operator= (const MateriaSource& cp)
{
	int	i;

	if (this != &cp)
	{
		i = 0;
		this->_size = cp._size;
		while (i < 4)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			this->_materia[i] = cp._materia[i];
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* val)
{
	if (this->_size >= 4)
		std::cout << "Too many Materias." << std::endl;
	else
	{
		this->_materia[_size] = val;
		this->_size++;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i;

	i = 0;
	while (i < 4 && this->_materia[i])
	{
		if (type == this->_materia[i]->getType())
			return (this->_materia[i]->clone());
		i++;
	}
	return (NULL);
}
