/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:40:44 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/01 19:37:34 by khovakim         ###   ########.fr       */
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
		Zombie(const std::string& name);
		~Zombie();
		
		void announce();
	
	private:
		const std::string mname;
};

Zombie* newZombie(std::string name);
void 	randomChump(std::string name);

#endif