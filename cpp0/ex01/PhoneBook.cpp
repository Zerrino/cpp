/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:44:11 by alexafer          #+#    #+#             */
/*   Updated: 2024/05/11 03:00:18 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::welcome(void) const
{

	std::cout << "|--------------------------------------|"<< std::endl;
	std::cout << "|                                      |"<< std::endl;
	std::cout << "|                Welcome               |"<< std::endl;
	std::cout << "|           To the PhoneBook           |"<< std::endl;
	std::cout << "|           Made by alexafer           |"<< std::endl;
	std::cout << "|             Please use :             |"<< std::endl;
	std::cout << "|         ADD / SEARCH / EXIT          |"<< std::endl;
	std::cout << "|                                      |"<< std::endl;
	std::cout << "|--------------------------------------|"<< std::endl;
}

void	PhoneBook::addContact(void)
{
	static int	i;

	this->_contacts[i % 8].init();
	this->_contacts[i % 8].setIndex(i % 8);
	i++;
}

void	PhoneBook::printContacts(void) const
{
	int	i;

	i = 0;
	while (i < 9)
	{
		this->_contacts[i].view(i);
		i++;
	}
}

int		PhoneBook::_readInput(void) const
{
	int	input;
	int	value;

	input = -1;
	value = 1;
	while (value)
	{
		std::cout << "Please enter the index >" << std::flush;
		std::cin >> input;
		if (std::cin.good() && (input >= 0 && input <= 8))
			value = 0;
		else
		{
			std::cin.clear();
			std::cout << "Invalid index, try again." << std::endl;
		}
	}
	return (input);
}

void	PhoneBook::search(void) const
{
	int	i;
	this->printContacts();
	i = this->_readInput();
	this->_contacts[i].display(i);
}
