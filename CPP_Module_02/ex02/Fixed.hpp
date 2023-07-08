/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:05:05 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/08 15:45:02 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __FIXED_HPP__
# define __FIXED_HPP__

# include <exception>
# include <iostream>
# include <string>
# include <cmath>

const std::string RESET       = "\033[0m";
const std::string BOLDRED     = "\033[1m\033[31m"; // Bold Red
const std::string BOLDBLUE    = "\033[1m\033[34m"; // Bold Blue
const std::string BOLDCYAN    = "\033[1m\033[36m"; // Bold Cyan
const std::string BOLDBLACK   = "\033[1m\033[30m"; // Bold Black
const std::string BOLDGREEN   = "\033[1m\033[32m"; // Bold Green
const std::string BOLDWHITE   = "\033[1m\033[37m"; // Bold White
const std::string BOLDYELLOW  = "\033[1m\033[33m"; // Bold Yellow
const std::string BOLDMAGENTA = "\033[1m\033[35m"; // Bold Magenta

class Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

	public:
		int  getRawBits() const;
		void setRawBits(int const raw);

		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator>(const Fixed& rhs)  const;
		bool operator<(const Fixed& rhs)  const;

		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		Fixed& operator++();
		Fixed& operator--();

		Fixed operator++(int);
		Fixed operator--(int);

		float toFloat(void) const;
		int   toInt(void) const;
	
		//  static member functions
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

	private:
		int              mfixedPointNumberValue;
		static const int mnumberOfFractionalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedNumber);

#endif
