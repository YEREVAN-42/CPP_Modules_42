/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:40:44 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/01 21:10:38 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <string>
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

class Zombie
{
	public:
		Zombie();
		Zombie(const std::string& name);
		~Zombie();
		
		void announce();
		void SetName(const std::string& name);
	
	private:
		std::string mname;
};

Zombie*    zombieHorde(int N, std::string name);

#endif