/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:03:13 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/28 02:19:55 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materia[4];
		int			_size;
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &cp);
		MateriaSource& operator= (const MateriaSource &cp);

		void		learnMateria(AMateria* val);
		AMateria*	createMateria(std::string const & type);
};

#endif
