/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:08:28 by alexafer          #+#    #+#             */
/*   Updated: 2024/10/11 13:45:38 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <sstream>
# include <string>

template <typename T>
void	reverse_stack(std::stack<T> &stack_full, std::stack<T> &stack_empty)
{
	while (stack_full.size())
	{
		stack_empty.push(stack_full.top());
		stack_full.pop();
	}
}

class	RPN
{
	private:
		std::string				_str;
		std::stack<int>			_nb;
		std::stack<std::string>	_ch;
		std::stack<std::string>	_stack;
	public:
		RPN();
		~RPN();
		RPN(const RPN &cp);
		RPN& operator= (const RPN &cp);
		void	getArgs(int argc, char **argv);
		void	verifyString(void);
		void	makeStack(void);
		void	verifyStack(void);
		void	getResult(void);
};

#endif
