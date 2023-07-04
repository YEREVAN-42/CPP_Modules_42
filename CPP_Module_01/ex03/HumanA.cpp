/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:49:24 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/04 22:56:06 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon)
: mname(name), mweapon(const_cast<Weapon&>(weapon))
{	}

HumanA::~HumanA()
{	}

void HumanA::attack() const
{
	std::cout << this->mname << " attacks with their ";
	std::cout << this->mweapon.GetType() << std::endl; 
}
