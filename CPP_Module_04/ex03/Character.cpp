/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:41:30 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 19:15:36 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : mname("?"), msize(0) {	}
Character::Character(const std::string& name) : mname(name), msize(0) {	}

Character::Character(const Character& other)
: mname(other.mname), msize(other.msize)
{
	for (std::size_t i = 0; i < other.msize; ++i) {
		this->minventory[i] = other.minventory[i]->clone();
	}
}

Character& Character::operator=(const Character& other)
{
	if (this == &other) {
		return *this;
	}
	
	for (std::size_t i = 0; i < this->msize; ++i) {
		delete this->minventory[i];
		this->minventory[i] = NULL;
	}

	for (std::size_t i = 0; i < other.msize; ++i) {
		this->minventory[i] = other.minventory[i]->clone();
	}

	static_cast<std::string>(this->mname) = other.mname;
	this->msize = other.msize;
	return *this;
}

Character::~Character()
{
	for (std::size_t i = 0; i < msize; ++i) {
		delete minventory[i];
		minventory[i] = NULL;
	}
}

const std::string& Character::getName() const { return this->mname; }

void Character::equip(AMateria* m)
{
	if (this->msize < 4) {
		this->minventory[(this->msize)++] = m;
	} else {
		std::cout << "No space" << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && static_cast<std::size_t>(idx) < this->msize) {
		// delete this->minventory[idx];
		while (++idx < static_cast<int>(this->msize)) {
			this->minventory[idx - 1] = this->minventory[idx];
		}
		this->minventory[idx] = NULL;
		--this->msize;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && static_cast<std::size_t>(idx) < this->msize) {
		this->minventory[idx]->use(target);
	}
}

