/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:47:53 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 10:13:15 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _signed(0), _gradeSign(0), _gradeReq(0)
{
}

AForm::AForm(std::string name, int gradeSign, int gradeReq)
	: _name(name), _signed(0), _gradeSign(gradeSign), _gradeReq(gradeReq)
{
	if (gradeSign > 150 || gradeReq > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeReq < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& cp)
	: _signed(0), _gradeSign(1), _gradeReq(1)
{
	*this = cp;
}

AForm& AForm::operator= (const AForm& cp)
{
	if (this != &cp)
	{
		this->_signed = cp._signed;
	}
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw ()
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw ()
{
	return ("Grade is too low!");
}

const char* AForm::FormNotSignException::what() const throw ()
{
	return ("Form isn't signed!");
}

void	AForm::beSigned(Bureaucrat &m)
{
	if (m.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	if (this->_signed)
		std::cout << "Form was already signed !" << std::endl;
	this->_signed = 1;
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSign() const
{
	return (this->_signed);
}

int	AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

int	AForm::getGradeReq() const
{
	return (this->_gradeReq);
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_gradeReq)
		throw GradeTooLowException();
	if (this->_signed == 0)
		throw FormNotSignException();
	takeAction();
}


std::ostream& operator<<(std::ostream& os, const AForm& b)
{
	os << "Form name : " << b.getName() << std::endl;
	os << "Form sign : " << b.getSign() << std::endl;
	os << "Form Grade sign : " << b.getGradeSign() << std::endl;
	os << "Form Grade required : " << b.getGradeReq();
	return (os);
}
