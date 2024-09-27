/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:52:43 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/27 14:41:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>

template <typename T>
int	easyfind(T& container, int val)
{
	for (typename T::iterator i = container.begin(); i != container.end(); ++i)
		if (*i == val)
			return (std::distance(container.begin(), i));
	return (-1);
}


#endif
