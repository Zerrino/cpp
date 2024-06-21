/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:30:58 by alexafer          #+#    #+#             */
/*   Updated: 2024/06/21 12:48:03 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NoSed.hpp"

int	main(int argc, char **argv)
{

	if (argc != 4)
		std::cerr << "Error: Usage is <filename> s1 s2" << std::endl;	
	else
	{
		NoSed file(argv[1], argv[2], argv[3]);
		file.replaceFile();
	}
	return (0);
}
