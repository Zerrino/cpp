/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:53:05 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/27 14:41:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>

int	main(void)
{
	std::vector<int>	vec_numbers;
	std::set<int>		set_numbers;

	vec_numbers.push_back(10);
	vec_numbers.push_back(20);
	vec_numbers.push_back(30);


	set_numbers.insert(10);
	set_numbers.insert(20);
	set_numbers.insert(30);

	std::cout << easyfind(vec_numbers, 20) << std::endl;
	std::cout << easyfind(set_numbers, 30) << std::endl;
	return (0);
}
