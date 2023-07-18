/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:08:11 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 19:12:45 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {	}
Ice::Ice(const Ice& other) : AMateria(other.mmateria) {	}
Ice::~Ice() {	}

Ice& Ice::operator=(const Ice& other)
{
	if (this == &other) {
		return *this;
	}
	static_cast<std::string>(this->mmateria) = other.mmateria;
	return *this;
}

void Ice::use(ICharacter& target) const
{ std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }

AMateria* Ice::clone() const { return new Ice(*this); }

// void Ice::use(ICharacter& target)
// { std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }
