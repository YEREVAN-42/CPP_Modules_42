/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:06:37 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/08 18:35:05 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	~Point();
	
	Point& operator=(const Point& other);

public:
	const Fixed getX() const;
	const Fixed getY() const;

	int getIntegerX() const;
	int getIntegerY() const;

private:
	const Fixed mx;
	const Fixed my;
};

std::ostream& operator<<(std::ostream& out, const Point& point);

#endif
