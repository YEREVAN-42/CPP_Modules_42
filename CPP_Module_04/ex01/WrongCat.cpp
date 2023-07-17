/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:32:47 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/17 16:39:28 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{ std::cout << "Default constructor called for WrongCat" << std::endl; }

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other.mtype)
{ std::cout << "Copy constructor called for WrongCat" << std::endl; }

WrongCat::~WrongCat()
{ std::cout << "Destructor called for WrongCat" << std::endl; }

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Copy assignment operator called for WrongCat" << std::endl;
	if (this == &other) {
		return *this;
	}
	this->mtype = other.mtype;
	return *this;
}

void WrongCat::makeSound() const
{ std::cout << "Meow" << std::endl; }