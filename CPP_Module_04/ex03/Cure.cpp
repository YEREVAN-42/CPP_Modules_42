/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:20:16 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 18:50:29 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {	}
Cure::Cure(const Cure& other) : AMateria(other.mmateria) {	}
Cure::~Cure() {	}

Cure& Cure::operator=(const Cure& other)
{
	if (this == &other) {
		return *this;
	}
	static_cast<std::string>(this->mmateria) = other.mmateria;
	return *this;
}

void Cure::use(ICharacter& target) const
{ std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }

AMateria* Cure::clone() const { return new Cure(*this); }

// void Cure::use(ICharacter& target)
// { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }