/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 07:29:00 by alexafer          #+#    #+#             */
/*   Updated: 2024/06/18 10:23:58 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	Zombie z1;
	int	i;
	int	n;


	z1.set("Alex");
	z1.announce();
	
	n = 5;
	i = 0;
	horde = zombieHorde(n, "Hello");
	while (i < n)
	{
		horde[i].announce();	
		i++;
	}
	delete [] horde;
	return (0);
}
