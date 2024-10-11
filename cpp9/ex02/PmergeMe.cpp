/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:31:24 by alexafer          #+#    #+#             */
/*   Updated: 2024/10/11 19:53:56 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& cp)
{
	*this = cp;
}

PmergeMe& PmergeMe::operator= (const PmergeMe& cp)
{
	if (this != &cp)
		*this = cp;
	return (*this);
}

template <typename T>
int	PmergeMe::iter(T &array, int (*func)(typename T::value_type&, typename T::value_type&))
{
	for (typename T::iterator it = array.begin(); (it + 1) != array.end(); ++it)
	{
		if (!func(*(it), *(it + 1)))
			return (0);
	}
	return (1);
}

template <typename T>
int	PmergeMe::printElements(T &element, T &element2)
{
	std::cout << element << " : " << element2 << std::endl;
	return (1);
}

void	PmergeMe::getArgs(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		this->_str += argv[i];
		i++;
		if (i < argc - 1)
			this->_str += " ";
	}
}

void	PmergeMe::fillCont(void)
{
	std::istringstream	iss(this->_str);
	std::string			word;

	while (iss >> word)
	{
		this->_deq.push_back(std::stoi((word)));
		this->_vec.push_back(std::stoi((word)));
		if (std::stoi(word) < 0)
			throw std::out_of_range("error negative number");
	}
	std::cout << std::endl;
	std::cout << "unsorted :";
	for (std::deque<int>::iterator it = this->_deq.begin(); it != this->_deq.end(); ++it)
	{
		std::cout << " " << *(it);
	}
	std::cout << std::endl << std::endl;
	this->_sta = std::clock();
	this->algorithmPmergeMe(this->_deq);
	this->_end = std::clock();
	this->_deqT = static_cast<double>(this->_end - this->_sta) / (CLOCKS_PER_SEC / 1000);

	this->_sta = std::clock();
	this->algorithmPmergeMe(this->_vec);
	this->_end = std::clock();
	this->_vecT = static_cast<double>(this->_end - this->_sta) / (CLOCKS_PER_SEC / 1000);
	std::cout << "sorted :";
	for (std::deque<int>::iterator it = this->_deq.begin(); it != this->_deq.end(); ++it)
	{
		std::cout << " " << *(it);
	}
	std::cout << std::endl;
	this->displayResult();
}

void	PmergeMe::displayResult(void)
{
	const int frameWidth = 48;
	const std::string red = "\033[31m";
	const std::string green = "\033[32m";
	const std::string reset = "\033[0m";
	std::string	resultDeq;
	std::string	resultVec;

	std::string	s1 = (this->iter(this->_deq, isSorted) ? green + "Yes" + reset : red + "No" + reset);
	std::string	s2 = (this->iter(this->_vec, isSorted) ? green + "Yes" + reset : red + "No" + reset);

	if (this->_vecT < this->_deqT)
	{
		resultDeq = red + std::to_string(this->_deqT) + reset;
		resultVec = green + std::to_string(this->_vecT) + reset;
	}
	else if (this->_vecT > this->_deqT)
	{
		resultDeq = green + std::to_string(this->_deqT) + reset;
		resultVec = red + std::to_string(this->_vecT) + reset;
	}
	else
	{
		resultDeq = green + std::to_string(this->_deqT) + reset;
		resultVec = green + std::to_string(this->_vecT) + reset;
	}
	std::cout << std::setfill('-') << std::setw(frameWidth) << "-" << std::endl << std::setfill(' ');
	std::cout << "| " << std::left << std::setw(frameWidth + 6) << "Time for vector   : " + resultVec + " milliseconds" << "|" << std::endl;
	std::cout << "| " << std::left << std::setw(frameWidth + 6) << "Time for deque    : " + resultDeq + " milliseconds" << "|" << std::endl;
	std::cout << "| " << std::left << std::setw(frameWidth + 6) << "Is vector sorted  : " + s1 << "|" << std::endl;
	std::cout << "| " << std::left << std::setw(frameWidth + 6) << "Is deque sorted   : " + s2 << "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(frameWidth) << "-" << std::endl;
}

template <typename T>
void PmergeMe::algorithmPmergeMe(T &contDeq)
{
	T de_max;
	T de_min;

	if (contDeq.size() <= 1)
		return;
	for (typename T::iterator it = contDeq.begin(); it != contDeq.end(); ++it)
	{
		if ((it + 1) != contDeq.end())
		{
			de_max.push_back(std::max(*(it), *(it + 1)));
			de_min.push_back(std::min(*(it), *(it + 1)));
			++it;
		}
		else
			de_max.push_back(*it);
	}
	algorithmPmergeMe(de_max);
	for (typename T::iterator it = de_min.begin(); it != de_min.end(); ++it)
	{
		typename T::iterator pos = std::upper_bound(de_max.begin(), de_max.end(), *it);
		de_max.insert(pos, *it);
	}
	contDeq = de_max;
}
