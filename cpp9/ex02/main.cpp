/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:31:27 by alexafer          #+#    #+#             */
/*   Updated: 2024/10/11 18:56:06 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	PM;

	if (argc < 2)
		return (std::cout << "use : " << argv[0] << " <positive numbers...>" << std::endl, 0);

	try
	{
		PM.getArgs(argc, (argv + 1));
		PM.fillCont();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
