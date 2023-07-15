/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:47:49 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/15 19:20:52 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : mtype("Non typed animal")
{ std::cout << "Default constructor called for Animal" << std::endl; }

Animal::Animal(const std::string& type) : mtype(type)
{ std::cout << "Constructor with parameters called for Animal" << std::endl; }

Animal::Animal(const Animal& other) : mtype(other.mtype)
{ std::cout << "Copy constructor called for Animal" << std::endl; }

Animal::~Animal()
{ std::cout << "Destructor called for Animal" << std::endl; }

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Copy assignment operator called for Animal" << std::endl;
	if (this == &other) {
		return *this;
	}
	this->mtype = other.mtype;
	return *this;
}

const std::string Animal::getType() const
{ return this->mtype; }

void Animal::makeSound() const
{ std::cout << "Animal sound" << std::endl;}
