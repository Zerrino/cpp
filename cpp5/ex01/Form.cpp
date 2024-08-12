/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:47:53 by alexafer          #+#    #+#             */
/*   Updated: 2024/08/12 20:07:22 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _signed(0), _gradeSign(0), _gradeReq(0)
{
}

Form::Form(std::string name, int gradeSign, int gradeReq)
	: _name(name), _signed(0), _gradeSign(gradeSign), _gradeReq(gradeReq)
{
	if (gradeSign > 150 || gradeReq > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeReq < 1)
		throw GradeTooHighException();
}

Form::~Form()
{
}

Form::Form(const Form& cp)
	: _signed(0), _gradeSign(1), _gradeReq(1)
{

	*this = cp;
}

Form& Form::operator= (const Form& cp)
{
	if (this != &cp)
	{
		this->_signed = cp._signed;
	}
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw ()
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw ()
{
	return ("Grade is too low!");
}

void	Form::beSigned(Bureaucrat m)
{

}
