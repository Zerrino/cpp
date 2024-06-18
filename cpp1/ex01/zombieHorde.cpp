/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:59:19 by alexafer          #+#    #+#             */
/*   Updated: 2024/06/18 10:16:53 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	int		i;

	horde = new Zombie[N];
	i = 0;
	while (i < N)
	{
		horde[i].set(name);	
		i++;
	}
	return (horde);
}

