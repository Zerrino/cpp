/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:24:05 by alexafer          #+#    #+#             */
/*   Updated: 2024/05/11 03:00:40 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int	main(void)
{
	PhoneBook	Book;
	std::string	input;

	input = "";	
	Book.welcome();
	while (input.compare("EXIT"))
	{
		if (!input.compare("ADD"))
			Book.addContact();
		else if (!input.compare("SEARCH"))
			Book.search();
		std::cout << "\033[35mPhoneBook >\033[0m" << std::flush;
		std::cin >> input;
	}
	return (0);
}
