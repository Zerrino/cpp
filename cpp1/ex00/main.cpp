/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:29:00 by alexafer          #+#    #+#             */
/*   Updated: 2024/06/18 09:53:08 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie z1("hey");
	z1.announce();
	randomChump("LOL");

	Zombie *salut = New_Zombie("cc");
	salut->announce();
	delete salut;

	return (0);
}
