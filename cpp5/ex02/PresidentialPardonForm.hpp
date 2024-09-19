/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:25:01 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 09:25:51 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <exception>
# include <iostream>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string _target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &cp);
		PresidentialPardonForm& operator= (const PresidentialPardonForm &cp);

		void	takeAction() const;
};

#endif
