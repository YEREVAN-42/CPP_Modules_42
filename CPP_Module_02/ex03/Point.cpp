/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:21:22 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/08 18:52:51 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : mx(0), my(0) {	}
Point::Point(const float x, const float y) : mx(x), my(y) { }
Point::Point(const Point& other) : mx(other.mx), my(other.my) { }
Point::~Point() { }

Point& Point::operator=(const Point& other)
{
	(void) other;
	std::cout << "Point has type <CONST FIXED> argument" << std::endl;
	return (*this);
}

const Fixed Point::getX() const { return mx; };
const Fixed Point::getY() const { return my; };

int Point::getIntegerX() const { return mx.toInt(); }
int Point::getIntegerY() const { return my.toInt(); }

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << "(" << point.getX() << ", " << point.getY() << ")";
	return out;
}
