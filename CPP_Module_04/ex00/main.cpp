/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:21:43 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/17 16:44:47 by khovakim         ###   ########.fr       */
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
	const Animal* meta = new Animal();
	const Animal* j    = new Dog();
	const Animal* i    = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
  meta->makeSound();

	// const WrongAnimal* wrongAnimal = new WrongAnimal();
	// const WrongAnimal* wrongCat    = new WrongCat();
	// // const WrongCat*    catCat      = new WrongCat();
	
	// std::cout << wrongCat->getType() << " " << std::endl;
  
	// // catCat->makeSound();
	// wrongCat->makeSound();
	// wrongAnimal->makeSound();
  return 0;
}
