/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 10:37:02 by alexafer          #+#    #+#             */
/*   Updated: 2024/10/06 11:04:46 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange btc;

	if (argc != 2)
		std::cout << "usage : " << argv[0] << " <data_input>" << std::endl;
	else
	{
		btc.BitcoinPath(argv[1]);
		try
		{
			btc.execute();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
