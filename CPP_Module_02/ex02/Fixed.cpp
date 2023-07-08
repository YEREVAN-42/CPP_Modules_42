/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:18:03 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/07 20:26:31 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: mfixedPointNumberValue(0)
{
	std::cout << BOLDGREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int value)
: mfixedPointNumberValue(value << mnumberOfFractionalBits)
{
	std::cout << BOLDWHITE << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(const float value)
: mfixedPointNumberValue(roundf(value * (1 << mnumberOfFractionalBits)))
{
	std::cout << BOLDMAGENTA << "Float constructor called" << RESET << std::endl;
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

int Fixed::toInt() const
{
	return mfixedPointNumberValue >> mnumberOfFractionalBits;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(mfixedPointNumberValue) / (1 << mnumberOfFractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedNumber)
{
	out << fixedNumber.toFloat();
	return out;
}
