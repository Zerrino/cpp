/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:49 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/27 01:37:20 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class	Animal
{
	private:

	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &cp);
		Animal& operator= (const Animal &cp);

		virtual Brain*		getBrain() const;
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
