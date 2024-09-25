/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:17:47 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/25 16:44:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		hey;
	Data		*bye;
	uintptr_t	val;

	hey.name = "Helro";
	hey.age = 14;
	hey.height = 160;

	val = Serializer::serialize(&hey);

	bye = Serializer::deserialize(val);

	std::cout << "value : " << val << std::endl;
	std::cout << "value : " << Serializer::serialize(bye) << std::endl;

	std::cout << hey.name << std::endl;
	std::cout << bye->name << std::endl;
	return (0);
}
