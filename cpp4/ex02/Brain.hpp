/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:25:17 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/27 00:36:11 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &cp);
		Brain& operator= (const Brain &cp);
		void	changeIdea(int index, std::string new_idea);
		void	showIdea(int index_1, int index_2);
		std::string	getIdea(int index);
};

#endif
