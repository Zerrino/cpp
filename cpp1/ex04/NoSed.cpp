/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoSed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:55:25 by alexafer          #+#    #+#             */
/*   Updated: 2024/06/21 13:52:43 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoSed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:31:34 by alexafer          #+#    #+#             */
/*   Updated: 2024/06/21 12:55:13 by alexafer         ###   ########.fr       */
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
		std::cout << val << std::endl;
		text.insert(text.length(), val);
		text.insert(text.length(), "\n");
	}
	std::cout << std::endl << std::endl << text << std::endl;
	
	
	new_file << text;
		
	file.close();
	new_file.close();
}
