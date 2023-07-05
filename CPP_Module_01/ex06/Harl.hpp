/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:11:18 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/05 15:42:27 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __HARL_HPP__
# define __HARL_HPP__

# include <iostream>

const std::string RESET       = "\033[0m";
const std::string BOLDRED     = "\033[1m\033[31m"; // Bold Red
const std::string BOLDBLUE    = "\033[1m\033[34m"; // Bold Blue
const std::string BOLDCYAN    = "\033[1m\033[36m"; // Bold Cyan
const std::string BOLDBLACK   = "\033[1m\033[30m"; // Bold Black
const std::string BOLDGREEN   = "\033[1m\033[32m"; // Bold Green
const std::string BOLDWHITE   = "\033[1m\033[37m"; // Bold White
const std::string BOLDYELLOW  = "\033[1m\033[33m"; // Bold Yellow
const std::string BOLDMAGENTA = "\033[1m\033[35m"; // Bold Magenta

class Harl
{
	public:
		void complain(std::string level);

	private:
		void info();
		void error();
		void debug();
		void warning();
};

#endif
