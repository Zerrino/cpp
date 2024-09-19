/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:07:53 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 09:31:25 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& cp)
	: _name(cp._name), _grade(cp._grade)
{
	*this = cp;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& cp)
{
	if (this != &cp)
	{
		this->_grade = cp._grade;
	}
	return (*this);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("Grade is too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("Grade is too low!");
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::signForm(AForm &m)
{
	try
	{
		m.beSigned(*this);
		std::cout << this->_name << " signed " << m.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn’t sign " << m.getName()
			<< " because " << e.what() << std::endl;
	}

}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " didn't executed " << form.getName()
			<< " because " << e.what() << std::endl;
	}

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
