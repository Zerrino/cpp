/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:02:41 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/28 02:52:12 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character : public ICharacter
{
	private:
		std::string _name;
		AMateria	*_inv[4];
	public:
		Character(std::string name);
		Character(const Character &cp);

		~Character();

		Character& operator= (const Character &cp);

		std::string	const & getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
