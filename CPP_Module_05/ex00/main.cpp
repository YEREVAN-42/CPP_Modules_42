/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:55:38 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/20 16:10:30 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat	obj("Bob", 10);
		std::cout << "------------------" << std::endl;
		std::cout << obj << std::endl;
		std::cout << "------------------" << std::endl;
		for (int i = 0; i < 5; ++i) {
			obj.decrement();
		}
		std::cout << "------------------" << std::endl;
		std::cout << obj << std::endl;
		std::cout << "------------------" << std::endl;
		for (int i = 0; i < 5; ++i) {
			obj.increment();
		}
		std::cout << "------------------" << std::endl;
		std::cout << obj << std::endl;
		std::cout << "------------------" << std::endl;
	} catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}