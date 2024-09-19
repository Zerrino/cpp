/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:25:01 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 09:41:20 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <exception>
# include <iostream>
# include <random>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string _target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &cp);
		RobotomyRequestForm& operator= (const RobotomyRequestForm &cp);

		void	takeAction() const;
};

#endif
