/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:43:52 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/08 18:48:16 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point);

static void	printData(const Point& a, const Point& b, const Point& c, const Point& p)
{
	std::cout << "Triangle vertices are " << std::endl;
	std::cout << "A" << a << ", B" << b << ", C" << c;
	std::cout << std::endl;
	std::cout <<"Point P is" << std::endl;
	std::cout << "P" << p << std::endl;
}

static void	test(const Point& a, const Point& b, const Point& c, const Point& p)
{
	printData(a, b, c, p);
	if (bsp(a, b, c, p))
		std::cout << "Point P is in the triangle ABC!" << std::endl;
	else
		std::cout << "Point P is NOT in the triangle ABC!" << std::endl;
}

int	main()
{
	Point	a1, b1(0, 4), c1(5, 0);
	Point	p1(1, 1);
	test(a1, b1, c1, p1);
	std::cout << std::endl;

	Point	a2, b2(0, 4), c2(5, 0);
	Point	p2(0, 0);
	test(a2, b2, c2, p2);
	std::cout << std::endl;

	Point	a3, b3(0, 4), c3(5, 0);
	Point	p3(0, 1);
	test(a3, b3, c3, p3);
	std::cout << std::endl;

	Point	a4(0.f, 0.f), b4(10.f, 30.f), c4(20.f, 0.f);
	Point	p4(10.f, 15.f);
	test(a4, b4, c4, p4);
	std::cout << std::endl;

	return (0);
}