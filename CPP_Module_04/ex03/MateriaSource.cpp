/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:25:42 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 18:51:33 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : msize(0) {	}


MateriaSource::MateriaSource(const MateriaSource &other)
: msize(other.msize)
{
	for (std::size_t i = 0; i < this->msize; ++i) {
		this->mmaterias[i] = other.mmaterias[i]->clone();
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other) {
		return *this;
	}
	for (std::size_t i = 0; i < this->msize; ++i) {
		delete this->mmaterias[i];
		this->mmaterias[i] = NULL;
	}

	for (std::size_t i = 0; i < other.msize; ++i) {
		this->mmaterias[i] = other.mmaterias[i]->clone();
	}
	this->msize = other.msize;

	return *this;
}

MateriaSource::~MateriaSource()
{
	for (std::size_t i = 0; i < this->msize; ++i) {
		delete this->mmaterias[i];
		this->mmaterias[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (this->msize < 4) {
		this->mmaterias[(this->msize)++] = materia;
	} else {
		std::cout << "No space" << std::endl;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (std::size_t i = 0; i < this->msize; ++i) {
		if (type == this->mmaterias[i]->getType()) {
			return this->mmaterias[i]->clone();
		}
	}

	return NULL;
}
