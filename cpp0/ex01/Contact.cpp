/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:44:00 by alexafer          #+#    #+#             */
/*   Updated: 2024/05/11 03:07:44 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

std::string	Contact::_getInput(std::string str) const
{
	std::string	input;
	int			value;

	input = "";
	value = 1;
	while (value)
	{
		std::cout << "Please enter your " << str << " >" << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			value = 0;
		else
		{
			std::cin.clear();
			std::cout << "Invalid " << str <<  " try again." << std::endl;
		}
	}
	return (input);
}

std::string	Contact::_printLen(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::init(void)
{
	std::cin.ignore();
	this->_firstName = this->_getInput("first name");
	this->_lastName = this->_getInput("last name");
	this->_nickName = this->_getInput("nickname");
	this->_phoneNumber = this->_getInput("phone number");
	this->_darkestSecret = this->_getInput("darkest secret");
}

void	Contact::view(int index) const
{
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName);
	std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName);
	std::cout << "|" << std::setw(10) << this->_printLen(this->_nickName);
	std::cout << "|" << std::endl;
}

void	Contact::display(int index) const
{
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << "Index : " << index << std::endl;
	std::cout << "First name : " << this->_firstName << std::endl;
	std::cout << "Last name : " << this->_lastName << std::endl;
	std::cout << "Nickname : " << this->_nickName << std::endl;
	std::cout << "Phone number : " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret : " << this->_darkestSecret << std::endl;
}

void	Contact::setIndex(int i)
{this->_index = i;}

