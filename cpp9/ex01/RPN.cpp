/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:08:28 by alexafer          #+#    #+#             */
/*   Updated: 2024/10/11 14:26:25 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& cp)
{
	*this = cp;
}

RPN& RPN::operator= (const RPN& cp)
{
	if (this != &cp)
		*this = cp;
	return (*this);
}

void	RPN::getArgs(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		this->_str += argv[i];
		this->_str += " ";
		i++;
	}
}

void	RPN::verifyString(void)
{
	char		arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '\n', '*', '+', '/', '-', '	'};
	int			size;
	std::string	str;

	size = sizeof(arr) / sizeof(char);
	for (std::string::iterator it = this->_str.begin(); it != this->_str.end(); ++it)
	{
		str = *(it);
		if (!(std::find(arr, arr + size, *(it)) != arr + size))
			throw std::out_of_range("error => '" + str + "'");
	}
}

void	RPN::makeStack(void)
{
	std::istringstream	iss(this->_str);
	std::stack<int>			temp_nb;
	std::stack<std::string>	temp_ch;
	std::stack<std::string>	temp_stack;
	std::string			word;
	int					nb;

	while (iss >> word)
	{
		if (word.length() == 1)
		{
			if (word == "-" || word == "+" || word == "*" || word == "/")
			{
				temp_ch.push(word);
				temp_stack.push(word);
			}
			else
			{
				nb = std::atoi(word.c_str());
				temp_nb.push(nb);
				temp_stack.push(word);
			}
		}
		else
		{
			nb = std::atoi(word.c_str());
			if (nb == 0)
				throw std::out_of_range("error => '" + word + "'");
			temp_nb.push(nb);
			temp_stack.push(word);
		}
	}
	reverse_stack(temp_nb, this->_nb);
	reverse_stack(temp_ch, this->_ch);
	reverse_stack(temp_stack, this->_stack);
}

void	RPN::verifyStack(void)
{
	int	n;

	n = this->_nb.size();
	n -= this->_ch.size();
	if (n < 1)
		throw std::out_of_range("error not enough number");
	if (n > 1)
		throw std::out_of_range("error not enough operator");
}

void	RPN::getResult(void)
{
	std::stack<int>	stack_nb;
	std::string	word;
	std::string	final_result;
	int	result;
	int	nb;
	int	nb_1;
	int	nb_2;

	while (this->_stack.size() > 0)
	{
		word = this->_stack.top();
		this->_stack.pop();
		if (word.length() == 1)
		{
			if (word == "-" || word == "+" || word == "*" || word == "/")
			{
				if (stack_nb.empty())
					throw std::out_of_range("error");
				nb_2 = stack_nb.top();
				stack_nb.pop();
				if (stack_nb.empty())
					throw std::out_of_range("error");
				nb_1 = stack_nb.top();
				stack_nb.pop();
				switch (*(word.c_str()))
				{
				case '-':
					result = nb_1 - nb_2;
					break;
				case '+':
					result = nb_1 + nb_2;
					break;
				case '*':
					result = nb_1 * nb_2;
					break;
				case '/':
					if (nb_2 == 0)
						throw std::out_of_range("error divison by zero");
					result = nb_1 / nb_2;
					break;
				default:
						throw std::out_of_range("error");
					break;
				}
				{
					std::ostringstream oss;
					oss << result;
					final_result = oss.str();
					if (this->_stack.size() != 0)
						this->_stack.push(final_result);
				}
			}
			else
			{
				nb = std::atoi(word.c_str());
				stack_nb.push(nb);
			}
		}
		else
		{
			nb = std::atoi(word.c_str());
			if (nb == 0)
				throw std::out_of_range("error => '" + word + "'");
			stack_nb.push(nb);
		}
	}
	std::cout << std::atoi(final_result.c_str()) << std::endl;
}
