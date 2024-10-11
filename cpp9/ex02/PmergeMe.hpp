/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:31:24 by alexafer          #+#    #+#             */
/*   Updated: 2024/10/11 19:43:58 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <sstream>
# include <string>
# include <ctime>
# include <iomanip>

template <typename T>
int	isSorted(T &element, T &element2)
{
	if (element <= element2)
		return (1);
	return (0);
}

class	PmergeMe
{
	private:
		std::deque<int>		_deq;
		std::vector<int>	_vec;
		std::string			_str;
		std::clock_t 		_sta;
		std::clock_t		_end;
		double				_vecT;
		double				_deqT;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cp);
		PmergeMe& operator= (const PmergeMe &cp);
		template <typename T>
		void	algorithmPmergeMe(T &contDeq);
		template <typename T>
		int		iter(T &array, int (*func)(typename T::value_type&, typename T::value_type&));
		template <typename T>
		int		printElements(T &element, T &element2);
		void	fillCont(void);
		void	getArgs(int argc, char **argv);
		void	displayResult(void);
};

#endif
