/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:07:53 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 07:39:31 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
		Bureaucrat();
	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &cp);
		Bureaucrat& operator= (const Bureaucrat &cp);


		class GradeTooHighException : public std::exception
		{const char* what() const throw();};
		class GradeTooLowException  : public std::exception
		{const char* what() const throw();};

		void incrementGrade();
		void decrementGrade();

		const std::string getName() const;
		int	getGrade() const;

		void	signForm(Form &m);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
