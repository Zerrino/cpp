/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:07:55 by alexafer          #+#    #+#             */
/*   Updated: 2024/06/26 13:44:24 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put "
		<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << ": I think I deserve to have some extra bacon for free. I’ve been coming for "
		<< "years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	functions	func[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	func_lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::size_t	i;

	i = 0;
	while (i < 4)
	{
		if (!level.compare(func_lvl[i]))
		{
			(this->*func[i])();
		}
		i++;
	}
}
