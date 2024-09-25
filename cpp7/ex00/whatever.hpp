/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:48:52 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/25 19:58:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return (a);
	if (a > b)
		return (b);
	return (b);
}

template <typename T>
T max(T a, T b)
{
	if (a < b)
		return (b);
	if (a > b)
		return (a);
	return (b);
}

template <typename T>
void	swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}


#endif
