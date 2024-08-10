/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:07:53 by alexafer          #+#    #+#             */
/*   Updated: 2024/08/09 15:10:38 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class	Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &cp);
		Bureaucrat& operator= (const Bureaucrat &cp);
		
		
		GradeTooHighException();
		GradeTooLowException();
		
		const std::string getName();
		int	getGrad();
};

#endif
