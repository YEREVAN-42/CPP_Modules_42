/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:59:20 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/01 21:04:23 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombies = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		zombies[i].SetName(name);
	}
	return zombies;
}
