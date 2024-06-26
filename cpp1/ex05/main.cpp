/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:07:42 by alexafer          #+#    #+#             */
/*   Updated: 2024/06/26 13:38:25 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string	input;
	Harl	harl;

	input = "";
	while (input.compare("STOP"))
	{
		std::cout << "input : ";
		std::cin >> input;
		harl.complain(input);
	}
	return (0);
}
