/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:40:28 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/08 18:42:57 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	sign(const Point p1, const Point p2, const Point p3)
{
	int	tmp;

	tmp = ((p1.getIntegerX() - p3.getIntegerX()) * (p2.getIntegerY() - p3.getIntegerY()) - 
			(p2.getIntegerX() - p3.getIntegerX()) * (p1.getIntegerY() - p3.getIntegerY()));
	return (tmp);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	int		s1, s2, s3;
	bool	has_neg, has_pos;

	s1 = sign(point, a, b);
	s2 = sign(point, b, c);
	s3 = sign(point, c, a);

	has_neg = (s1 <= 0) || (s2 <= 0) || (s3 <= 0);
	has_pos = (s1 >= 0) || (s2 >= 0) || (s3 >= 0);

	return (!(has_neg && has_pos));
}
