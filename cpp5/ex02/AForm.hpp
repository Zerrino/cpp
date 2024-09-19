/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:47:53 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 10:13:05 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	private:
		const std::string _name;
		bool	_signed;
		const int	_gradeSign;
		const int	_gradeReq;
		AForm();
	public:
		AForm(std::string name, int gradeSign, int gradeReq);
		virtual ~AForm() = 0;
		AForm(const AForm &cp);
		AForm& operator= (const AForm &cp);

		class GradeTooHighException : public std::exception
		{const char* what() const throw();};
		class GradeTooLowException : public std::exception
		{const char* what() const throw();};
		class FormNotSignException : public std::exception
		{const char* what() const throw();};

		virtual const std::string getName() const;
		virtual bool		getSign() const;
		virtual int	getGradeSign() const;
		virtual int	getGradeReq() const;

		virtual void	beSigned(Bureaucrat &m);
		void	execute(Bureaucrat const & executor) const;
		virtual void	takeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif
