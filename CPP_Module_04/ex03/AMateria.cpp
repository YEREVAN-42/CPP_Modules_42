/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:47 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 16:59:27 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : mmateria("") {	}
AMateria::AMateria(const std::string& materia) : mmateria(materia) {	}
AMateria::AMateria(const AMateria& other) : mmateria(other.mmateria) {	}
AMateria::~AMateria() {	}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this == &other) {
		return *this;
	}
	static_cast<std::string>(this->mmateria) = other.mmateria;
	return *this;
}

const std::string& AMateria::getType() const { return this->mmateria; }

// void AMateria::use(ICaracter& target) { (void)target; }
