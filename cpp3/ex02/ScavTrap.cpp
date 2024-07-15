/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:24:00 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/15 12:55:23 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_func = __func__;
	this->_hit_points = 100;
	this->_egy_points = 50;
	this->_atk_damage = 20;
	this->_gate_keeper = 0;
	std::cout << "ScavTrap " << name << " was made!" << std::endl;
}


ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " got deconstructed!" << std::endl;	
}

void	ScavTrap::guardGate(void)
{
	if (!this->_gate_keeper)
	{
		std::cout << this->_func << " " << this->_name << " is now in Gate keeper mode!" << std::endl;
		this->_gate_keeper = 1;
	}
	else if (this->_gate_keeper)
	{
		std::cout << this->_func << " " << this->_name << " is no longer in Gate keeper mode!" << std::endl;
		this->_gate_keeper = 0;
	}
}
