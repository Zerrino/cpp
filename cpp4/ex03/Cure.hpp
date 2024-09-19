/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:02:41 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 08:58:32 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Cure : public AMateria
{
	private:

	public:
		Cure();
		~Cure();
		Cure(const Cure &cp);

		Cure& operator= (const Cure &cp);

		AMateria*	clone() const;
		void		use(ICharacter& target);

};

#endif
