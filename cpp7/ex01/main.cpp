/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:59:52 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/25 20:15:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::string Names[] = {"Anthony", "Marco", "Prout", "Alex", "Alo"};
	int			Nb[] = {1, 7, 9, 17, 0, -5};

	iter(Names, sizeof(Names) / sizeof(std::string), printElements);
	iter(Nb, sizeof(Nb) / sizeof(int), printElements);
	return (0);
}
