/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:24:09 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/15 12:56:31 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ScavTrap test("test!");

	test.attack("Bad");
	test.guardGate();
	test.guardGate();
	return (0);
}
