/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:21:43 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/17 17:56:38 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

int main()
{
	const Animal* x = new Dog();
	const Animal* y = new Cat();
	delete x;//should not create a leak
	delete y;
	std::cout << "***************" << std::endl;

	Animal *arr[10];

	for (int i = 0; i < 10; ++i) {
		if ((i & 1) == 0) {
			arr[i] = new Cat();
		} else {
			arr[i] = new Dog(); 
		}
		std::cout << "-------------" << std::endl;
	}

	for (int i = 0; i < 10; ++i) {
		delete arr[i];
	}
    // system("leaks fire");
  return 0;
}
