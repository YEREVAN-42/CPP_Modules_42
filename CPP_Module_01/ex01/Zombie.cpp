/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:52:37 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/01 19:27:53 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{ }

Zombie::Zombie(const std::string& name)
: mname(name)
{
	std::cout << BOLDRED << mname << ": zombie is coming" << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << BOLDGREEN << mname << ": zombie was died" << RESET << std::endl;
}

void Zombie::announce()
{
	std::cout << BOLDCYAN << mname << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::SetName(const std::string& name) { this->mname = name; }
