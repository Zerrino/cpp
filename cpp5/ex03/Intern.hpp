/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:25:28 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 11:55:48 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <exception>
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern(const Intern &cp);
		Intern& operator= (const Intern &cp);

		class NoFormException : public std::exception
		{const char* what() const throw();};

		AForm*	makeForm(std::string form, std::string target);
};

#endif
