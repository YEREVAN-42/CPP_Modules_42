/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:07:01 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/17 16:16:07 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{ std::cout << "Default constructor called for Dog" << std::endl; }

Dog::Dog(const Dog& other) : Animal(other.mtype)
{ std::cout << "Copy constructor called for Dog" << std::endl; }

Dog::~Dog()
{ std::cout << "Destructor called for Dog" << std::endl; }

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Copy assignment operator called for Dog";
	if (this == &other) {
		return *this;
	}
	this->mtype = other.mtype;
	return *this;
}

void Dog::makeSound() const
{ std::cout << "Gaf" << std::endl; } 
