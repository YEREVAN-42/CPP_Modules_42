/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:21:43 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 14:43:01 by khovakim         ###   ########.fr       */
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
	// Animal a();
	const Animal* x = new Dog();
	const Animal* y = new Cat();
	delete x;
	delete y;
	std::cout << "***************" << std::endl;

	Animal *arr[5];

	for (int i = 0; i < 5; ++i) {
		if ((i & 1) == 0) {
			arr[i] = new Cat();
		} else {
			arr[i] = new Dog(); 
		}
		std::cout << "-------------" << std::endl;
	}

	for (int i = 0; i < 5; ++i) {
		delete arr[i];
	}
    // system("leaks fire");
  return 0;
}
