/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoSed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:31:34 by alexafer          #+#    #+#             */
/*   Updated: 2024/06/24 12:03:30 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NoSed.hpp"

NoSed::NoSed(std::string path, std::string s1, std::string s2)
	:	_path(path), _s1(s1), _s2(s2)
{
}

NoSed::~NoSed(void)
{
}

void	NoSed::replaceFile(void)
{
	std::string	new_file_path;
	std::string	val;
	std::string	text;
	std::string	new_text;
	std::string	sub_text;
	std::size_t	found;

	std::ifstream file(this->_path);
	if (!file.is_open())
	{
		std::cerr << "Error opening the file!" << std::endl;
		return ;
	}
	new_file_path = this->_path;
	new_file_path.insert(new_file_path.length(), ".replace");
	std::ofstream new_file(new_file_path);	
	if (!new_file.is_open())
	{
		std::cerr << "Error opening the file!" << std::endl;
		file.close();
		return ;
	}
	text = "";
	while (std::getline(file, val))
	{
		text.insert(text.length(), val);
		text.insert(text.length(), "\n");
	}
	new_text = "";
	found = 0;
	while (found < text.length())
	{
		found = text.find(this->_s1);
		sub_text = text.substr(0, found);
		text = text.substr(found + this->_s1.length());
		new_text.insert(new_text.length(), sub_text);
		new_text.insert(new_text.length(), this->_s2);
	}
	new_text.insert(new_text.length(), "\n");
	new_file << new_text;
	file.close();
	new_file.close();
}
