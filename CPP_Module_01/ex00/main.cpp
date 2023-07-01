/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:36:11 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/01 19:38:16 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* z;

	z = newZombie("Salamander");
	z->announce();

	randomChump("Boria");

	delete z;
	return 0;
}