/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:44:16 by alexafer          #+#    #+#             */
/*   Updated: 2024/05/11 02:49:45 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{

	private:
		Contact	_contacts[8];
		int		_readInput(void) const;
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(void);
		void	printContacts(void) const;
		void	search(void) const;
		void	welcome(void) const;
};

#endif
