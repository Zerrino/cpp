/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:02:41 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/28 02:52:40 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name)
	: _name(name)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		this->_inv[i] = NULL;
		i++;
	}
}

Character::~Character()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->_inv[i])
			delete this->_inv[i];
		i++;
	}
}

Character::Character(const Character& cp)
{
	*this = cp;
}

Character& Character::operator= (const Character& cp)
{
	int	i;

	if (this != &cp)
	{
		this->_name = cp._name;
		i = 0;
		while (i < 4)
		{
			if (this->_inv[i])
				delete this->_inv[i];
			this->_inv[i] = cp._inv[i];
			i++;
		}
	}
	return (*this);
}

const std::string&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!this->_inv[i])
		{
			this->_inv[i] = m;
			i = 9;
		}
		i++;
	}
	if (i == 4)
		std::cout << "No place left." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	this->_inv[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (!this->_inv[idx])
		return ;
	this->_inv[idx]->use(target);
}
