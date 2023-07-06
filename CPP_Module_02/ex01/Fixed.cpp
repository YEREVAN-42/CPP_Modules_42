/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:18:03 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/06 21:38:52 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: mfixedPointNumberValue(0)
{
	std::cout << BOLDGREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::~Fixed()
{
	std::cout << BOLDRED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other)
: mfixedPointNumberValue(other.mfixedPointNumberValue)
{
	std::cout << BOLDYELLOW << "Copy constructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other) {
		return *this;
	}
	std::cout << BOLDCYAN << "Copy assignment operator called" << RESET << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	this->mfixedPointNumberValue = raw;
}

int Fixed::getRawBits() const
{
	std::cout << BOLDBLUE << "getRawBits member function called" << RESET << std::endl;
	return this->mfixedPointNumberValue;
}
