/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:39:14 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/11 18:52:28 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: mname("unknown"), mhitPoint(10), menergyPoint(10), mattackDamage(0)
{
	std::cout << "ClapTrap default constructor is called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
: mname(name), mhitPoint(10), menergyPoint(10), mattackDamage(0)
{
	std::cout << "ClapTrap constructor whith parameters is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
: mname(other.mname), mhitPoint(other.mhitPoint),
	menergyPoint(other.menergyPoint), mattackDamage(other.mattackDamage)
{
	std::cout << "ClapTrap copy constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor is called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator is called" << std::endl;
	if (this == &other) {
		return *this;
	}
	mname = other.mname;
	mhitPoint = other.mhitPoint;
	menergyPoint = other.menergyPoint;
	mattackDamage = other.mattackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (menergyPoint == 0 || mhitPoint == 0) {
		return ;
	}
	--menergyPoint;
	std::cout << "ClapTrap " << mname << " attacks " << target;
	if (mattackDamage > 0) {
		std::cout << ", causing " << mattackDamage << " points of damage!";
		std::cout << " Energy Points: " << menergyPoint << std::endl;
	} else {
		std::cout << ", but causes no damage" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (mhitPoint == 0) {
		return ;
	}
	if (mhitPoint < amount) {
		mhitPoint = amount;
	}
	mhitPoint -= amount;
	std::cout << "ClapTrap " << mname << " takes " << amount;
	std::cout << " points of damage!" << " Hit Points: " <<	mhitPoint;
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (mhitPoint == 0) {
		return ;
	}
	if (menergyPoint == 0) {
		std::cout << "ClapTrap " << mname;
		std::cout << " does not have enough energy to be repaired. ";
		std::cout << "Energy: " << menergyPoint << "." << std::endl;
	} else {
		--menergyPoint;
		mhitPoint += amount;
		std::cout << "ClapTrap " << mname;
		std::cout << " got repaired by " << amount << " points! ";
		std::cout << "Hit Points: " << mhitPoint << "." << std::endl;
	}
}
