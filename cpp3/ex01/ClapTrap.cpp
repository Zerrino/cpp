/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:43:24 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/15 08:43:25 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	:	_name(name), _hit_points(10), _egy_points(10), _atk_damage(0), _func(__func__)
{
	std::cout << this->_func << " " << name << " was made!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->_func << " " << _name << " got deconstructed!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_egy_points > 0)
	{
		std::cout << this->_func << " " << this->_name << " attacks "
			<< target <<", causing " << this->_atk_damage 
			<< " points of damage!" << std::endl;
		this->_egy_points = this->_egy_points - 1;
		std::cout << this->_func << " " << this->_name << " lost one energy point! "
		  << this->_egy_points << " remaining!" << std::endl;	
	}
	else
		std::cout << this->_func  << " " << this->_name << " has no energy points to attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int	i;

	i = 0;
	while (i < amount && this->_hit_points)
	{
		this->_hit_points = this->_hit_points - 1;
		i++;
	}
	if (amount == 0)
	{
		std::cout << this->_func << " " << this->_name << " took no damage!" 
			<< " Remaining Hit point : " << this->_hit_points << std::endl;
	}
	else if (i == 0)
		std::cout << this->_func << " " << this->_name << " have already died!" << std::endl;
	else if (amount > i)
	{
		std::cout << this->_func << " " << this->_name << " died from the attack!" << std::endl;
	}
	else
	{
		std::cout << this->_func << " " << this->_name << " has taken " << i << " damage!"
			<< " Remaining Hit point : " << this->_hit_points << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_egy_points == 0)
	{
		std::cout << this->_func << " " << this->_name << " can't be repaired! No energy left." << std::endl;
	}
	else
	{
		this->_egy_points -= 1;
		this->_hit_points += amount;
		std::cout << this->_func << " " << this->_name << " got repaired by " << amount << " he has now " << this->_hit_points
			<< " hit points!" << std::endl;
	}
}
