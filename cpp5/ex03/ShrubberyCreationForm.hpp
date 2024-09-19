/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:25:01 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 09:57:30 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <exception>
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string _target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &cp);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm &cp);

		class CantOpenFile : public std::exception
		{const char* what() const throw();};
		void	takeAction() const;
};

#endif
