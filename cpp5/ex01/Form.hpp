/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:47:53 by alexafer          #+#    #+#             */
/*   Updated: 2024/08/12 20:07:25 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string _name;
		bool	_signed;
		const int	_gradeSign;
		const int	_gradeReq;
		Form();
	public:
		Form(std::string name, int gradeSign, int gradeReq);
		~Form();
		Form(const Form &cp);
		Form& operator= (const Form &cp);

		class GradeTooHighException : public std::exception
		{const char* what() const throw();};
		class GradeTooLowException : public std::exception
		{const char* what() const throw();};

		void	beSigned(Bureaucrat m);
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif
