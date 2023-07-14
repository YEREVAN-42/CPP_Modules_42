/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:25:45 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/14 14:28:11 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap()
{
	mattackDamage = 20;
	menergyPoint  = 50;
	mhitPoint     = 100;
	
	std::cout << "Default constructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name)
{
	mattackDamage = 20;
	menergyPoint  = 50;
	mhitPoint     = 100;

	std::cout << "Constructor with parameters called for ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other.mname)
{
	mhitPoint     = other.mhitPoint;
	menergyPoint  = other.menergyPoint;
	mattackDamage = other.mattackDamage;

	std::cout << "Copy constructor called for ScavTrap" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy constructor called for ScavTrap" << std::endl;
	if (this == &other) {
		return *this;
	}
	mname         = other.mname;
	mhitPoint     = other.mhitPoint;
	menergyPoint  = other.menergyPoint;
	mattackDamage = other.mattackDamage;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (menergyPoint == 0 || mhitPoint == 0) {
		return ;
	}
	--menergyPoint;
	std::cout << "ScavTrap " << mname << " attacks " << target;
	if (mattackDamage > 0) {
		std::cout << ", causing " << mattackDamage << " points of damage!";
		std::cout << " Energy Points: " << menergyPoint << std::endl;
	} else {
		std::cout << ", but causes no damage" << std::endl;
	}
}

void ScavTrap::guardGate() const
{ std::cout << "ScavTrap " << mname << " has entered Gate keeper mode." << std::endl; }
