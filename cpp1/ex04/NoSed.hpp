/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NoSed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexafer <alexafer@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:31:48 by alexafer          #+#    #+#             */
/*   Updated: 2024/09/19 09:58:30 by alexafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOSED_HPP
# define NOSED_HPP

# include <iostream>
# include <fstream>

class	NoSed
{
	private:
		std::string	_path;
		std::string	_s1;
		std::string	_s2;
	public:
		NoSed(std::string path, std::string s1, std::string s2);
		~NoSed(void);
		void	replaceFile(void);
};

#endif
