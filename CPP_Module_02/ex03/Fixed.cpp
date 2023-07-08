/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:18:03 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/08 15:46:54 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: mfixedPointNumberValue(0)
{	}

Fixed::Fixed(const int value)
: mfixedPointNumberValue(value << mnumberOfFractionalBits)
{	}

Fixed::Fixed(const float value)
: mfixedPointNumberValue(roundf(value * (1 << mnumberOfFractionalBits)))
{	}

Fixed::~Fixed()
{	}

Fixed::Fixed(const Fixed& other)
: mfixedPointNumberValue(other.mfixedPointNumberValue)
{	}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other) {
		return *this;
	}
	this->setRawBits(other.getRawBits());
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	this->mfixedPointNumberValue = raw;
}

int Fixed::getRawBits() const
{
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

bool Fixed::operator>(const Fixed& rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return this->getRawBits() != rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return this->getRawBits() <= rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	if (rhs.getRawBits() == 0) {
		throw std::logic_error("Division by zero");
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++()
{
	++this->mfixedPointNumberValue;
	return *this;
}

Fixed& Fixed::operator--()
{
	--this->mfixedPointNumberValue;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	
	++this->mfixedPointNumberValue;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	
	--this->mfixedPointNumberValue;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a > b ? b : a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a > b ? b : a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}