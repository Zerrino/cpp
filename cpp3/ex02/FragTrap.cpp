/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:01:16 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/15 16:05:09 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_func = __func__;
	this->_hit_points = 100;
	this->_egy_points = 100;
	this->_atk_damage = 30;
	std::cout << "FragTrap " << name << " was made!" << std::endl;
}


FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " got deconstructed!" << std::endl;	
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_func << " " << this->_name << " made a positive high fives!" << std::endl;
}
