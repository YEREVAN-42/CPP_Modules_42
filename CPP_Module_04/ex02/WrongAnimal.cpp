/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:32:53 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/17 16:34:40 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : mtype("Non typed WrongAnimal")
{ std::cout << "Default constructor called for WrongAnimal" << std::endl; }

WrongAnimal::WrongAnimal(const std::string& type) : mtype(type)
{ std::cout << "Constructor with parameters called for WrongAnimal" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal& other) : mtype(other.mtype)
{ std::cout << "Copy constructor called for WrongAnimal" << std::endl; }

WrongAnimal::~WrongAnimal()
{ std::cout << "Destructor called for WrongAnimal" << std::endl; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "Copy assignment operator called for WrongAnimal" << std::endl;
	if (this == &other) {
		return *this;
	}
	this->mtype = other.mtype;
	return *this;
}

const std::string WrongAnimal::getType() const
{ return this->mtype; }

void WrongAnimal::makeSound() const
{ std::cout << "Animal sound" << std::endl;}
