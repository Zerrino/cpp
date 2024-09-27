/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:42:41 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/27 15:28:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>



class	Span
{
	private:
		unsigned int	_N;
		unsigned int	_I;
		std::vector<int> _numbers;
		Span();
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &cp);
		Span& operator= (const Span &cp);

		void	addNumber(int number);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
};

#endif
