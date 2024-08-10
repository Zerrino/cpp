/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:07:55 by alexafer          #+#    #+#             */
/*   Updated: 2024/08/10 19:25:19 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat john("John", 5);
		std::cout << john << std::endl;
		john.incrementGrade();
		std::cout << john << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
