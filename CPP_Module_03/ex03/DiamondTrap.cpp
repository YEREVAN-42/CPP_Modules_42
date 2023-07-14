/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:48:40 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/14 14:28:21 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	mhitPoint     = FragTrap::mhitPoint;
	menergyPoint  = ScavTrap::menergyPoint;
	mattackDamage = FragTrap::mattackDamage;
	std::cout << "Default constructor called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
: mname(name)
{
	mhitPoint       = FragTrap::mhitPoint;
	menergyPoint    = ScavTrap::menergyPoint;
	mattackDamage   = FragTrap::mattackDamage;
	ClapTrap::mname = mname + "_clap_name";
	std::cout << "Constructor with parameters called for DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: mname(other.mname)
{
	mhitPoint       = other.mhitPoint;
	menergyPoint    = other.menergyPoint;
	mattackDamage   = other.mattackDamage;
	std::cout << "Copy constructor called for DiamondTrap" << std::endl;

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "Copy assignment operator called for DiamondTrap" << std::endl;
	if (this == &other) {
		return *this;
	}
	mname         = other.mname;
	mhitPoint     = other.mhitPoint;
	menergyPoint  = other.menergyPoint;
	mattackDamage = other.mattackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called for DiamondTrap" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << mname << " : " << ClapTrap::mname << std::endl;
}
