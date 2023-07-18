/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:27:53 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 21:01:42 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), mbrain(new Brain())
{ std::cout << "Default constructor called for Cat" << std::endl; }

Cat::Cat(const Cat& other) : Animal(other.mtype), mbrain(new Brain(*other.mbrain))
{
	mbrain = other.mbrain;
	std::cout << "Copy constructor called for Cat" << std::endl; }

Cat::~Cat()
{ 
	delete mbrain;
	std::cout << "Destructor called for Cat" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Copy assignment operator called for Cat" << std::endl;
	if (this == &other) {
		return *this;
	}
	this->mtype = other.mtype;
	*this->mbrain = *other.mbrain;
	return *this;
}

void Cat::makeSound() const
{ std::cout << "Meow" << std::endl; }