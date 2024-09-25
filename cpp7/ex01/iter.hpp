/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:59:38 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/25 20:09:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef>

template <typename T>
void	iter(T *array, size_t len, void (*func)(T&))
{
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void	printElements(T &element)
{
	std::cout << element << std::endl;
}

#endif
