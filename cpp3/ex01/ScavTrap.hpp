/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:24:00 by alexafer          #+#    #+#             */
/*   Updated: 2024/07/15 12:52:58 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	private:
		bool	_gate_keeper;
	public:
		ScavTrap(std::string name);
		~ScavTrap(void);

		void	guardGate(void);
};

#endif
