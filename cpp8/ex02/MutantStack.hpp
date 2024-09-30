/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:40:32 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/30 21:54:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack &cp) {};
		MutantStack& operator= (const MutantStack &cp)
		{
			if (*this != &cp)
			{
			}
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {return this->c.begin();};
		iterator end() {return this->c.end();};
		iterator begin() const {return this->c.begin();};
		iterator end() const {return this->c.end();};
};

#endif
