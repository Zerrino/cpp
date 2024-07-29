/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:55 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/27 01:47:43 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

#define NB_ANIMAL 10

int main()
{
	/*
	Animal	*animals[NB_ANIMAL];
	int		i;

	i = 0;
	while (i < NB_ANIMAL)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		i++;
	}
	(animals[0]->getBrain())->changeIdea(1, "Trop"),
	(animals[1]->getBrain())->changeIdea(1, "Blop"),
	(animals[2]->getBrain())->changeIdea(1, "Prout"),
	(animals[0]->getBrain())->showIdea(1, 2);
	(animals[1]->getBrain())->showIdea(1, 2);
	(animals[2]->getBrain())->showIdea(1, 2);
	i = 0;
	while (i < NB_ANIMAL)
	{
		delete animals[i];
		i++;
	}
	*/
	Dog Nola;
	Cat	Tequila;

	Dog Nola_copy(Nola);
	Cat Tequila_copy(Tequila);

	(Tequila.getBrain())->changeIdea(1, "Lol");
	(Tequila_copy.getBrain())->changeIdea(1, "Hey");
	(Nola.getBrain())->changeIdea(1, "Ohh");
	(Nola_copy.getBrain())->changeIdea(1, "AAA");

	(Tequila.getBrain())->showIdea(1, 2);
	(Tequila_copy.getBrain())->showIdea(1, 2);
	(Nola.getBrain())->showIdea(1, 2);
	(Nola_copy.getBrain())->showIdea(1, 2);

	return (0);
}
