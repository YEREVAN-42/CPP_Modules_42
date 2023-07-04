/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:15:56 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/04 23:25:09 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
: mname(name), mweapon(NULL)
{	}

HumanB::~HumanB()
{	}

void HumanB::SetWeapon(Weapon& weapon)
{
	this->mweapon = &weapon;
}

void HumanB::attack() const
{
	std::cout << this->mname << " attacks with their ";
	std::cout << this->mweapon->GetType() << std::endl; 
}
