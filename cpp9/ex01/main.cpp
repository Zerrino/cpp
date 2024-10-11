/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:08:30 by alexafer          #+#    #+#             */
/*   Updated: 2024/10/11 13:44:28 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	rpn;

	if (argc <= 1)
		return (std::cout << "not enough arguments." << std::endl, 0);
	try
	{
		rpn.getArgs(argc, &argv[1]);
		rpn.verifyString();
		rpn.makeStack();
		rpn.verifyStack();
		rpn.getResult();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
