/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:09:06 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/14 14:28:08 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap()
{
	mhitPoint     = 100;
	menergyPoint  = 100;
	mattackDamage = 30;
	std::cout << "Default constructor called for FragTrap" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
: ClapTrap(name)
{
	mhitPoint     = 100;
	menergyPoint  = 100;
	mattackDamage = 30;
	std::cout << "Constructor with parameters called for FragTrap" << std::endl;
	
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other.mname)
{
	mhitPoint     = other.mhitPoint;
	menergyPoint  = other.menergyPoint;
	mattackDamage = other.mattackDamage;
	std::cout << "Copy constructor called for FragTrap" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Copy assignment operator called for FragTrap" << std::endl;
	if (this == &other) {
		return *this;
	}
	mname         = other.mname;
	mhitPoint     = other.mhitPoint;
	menergyPoint  = other.menergyPoint;
	mattackDamage = other.mattackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called for FragTrap" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (menergyPoint == 0 || mhitPoint == 0) {
		return ;
	}
	--menergyPoint;
	std::cout << "FragTrap " << mname << " attacks " << target;
	if (mattackDamage > 0) {
		std::cout << ", causing " << mattackDamage << " points of damage!";
		std::cout << " Energy Points: " << menergyPoint << std::endl;
	} else {
		std::cout << ", but causes no damage" << std::endl;
	}
}

void    FragTrap::highFivesGuys()
{
	std::cout << mname << " hello everyone " << std::endl;
}
