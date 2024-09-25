/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:48:52 by zerrino           #+#    #+#             */
/*   Updated: 2024/09/25 17:10:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"
#include "B.hpp"
#include "A.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	srand(time(0));
	int randomNumber = (rand() % 3);

	if (randomNumber == 0)
		return new A;
	else if (randomNumber == 1)
		return new B;
	else
		return new C;
	return (0);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknow" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch(...)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b;
		}
		catch(...)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void)c;
			}
			catch(...)
			{
				std::cout << "Unknow" << std::endl;
			}
		}
	}
}

int	main(void)
{
	Base *p;
	p = generate();

	identify(p);
	identify(*p);

	delete p;
	return (0);
}
