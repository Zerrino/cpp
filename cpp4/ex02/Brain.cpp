/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:25:17 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/27 01:46:57 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "A brain got made!" << std::endl;
	int	i;

	i = 0;
	while (i < 100)
	{
		this->_ideas[i] = "idea nb " + std::to_string(i);
		i++;
	}
}

Brain::~Brain()
{
	std::cout << "A brain got destroyed!" << std::endl;
}

Brain::Brain(const Brain& cp)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		this->_ideas[i] = cp._ideas[i];
		i++;
	}
}

Brain& Brain::operator= (const Brain& cp)
{
	int	i;

	if (this != &cp)
	{
		i = 0;
		while (i < 100)
		{
			this->_ideas[i] = cp._ideas[i];
			i++;
		}
	}
	return (*this);
}

void	Brain::changeIdea(int index, std::string new_idea)
{
	this->_ideas[index] = new_idea;
}

std::string	Brain::getIdea(int index)
{
	return (this->_ideas[index]);
}

void	Brain::showIdea(int index_1, int index_2)
{
	if (index_1 > index_2)
		return ;
	if (index_1 < 0 || index_1 > 100)
		return ;
	if (index_2 < 0 || index_2 > 100)
		return ;
	while (index_1 < index_2)
	{
		std::cout << this->getIdea(index_1) << std::endl;
		index_1++;
	}
}
