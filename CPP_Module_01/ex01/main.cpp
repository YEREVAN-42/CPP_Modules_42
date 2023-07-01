/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:05:09 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/01 21:14:25 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Z;
	int	n;

	std::cout << BOLDBLUE << "ENTER THE NUMBER OF ZOMBIES:" << RESET << std::endl;
	std::cin >> n;
	if (std::cin.fail()) {
		std::cerr << BOLDRED << "WRONG INPUT" << RESET << std::endl;
	}
	Z = zombieHorde(n, "salamander");

	for (int i = 0; i < n; i++)
		Z[i].announce();
	
	delete[] Z;
	return (0);
}