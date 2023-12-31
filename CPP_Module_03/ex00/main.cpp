/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:48:19 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/13 22:30:51 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap salamander("Salamander");
	ClapTrap unname;

    salamander.setAttackDamage(20);
    salamander.attack("Zombie");
    salamander.takeDamage(2);
    salamander.beRepaired(1);

	unname.attack("Zombie");
    unname.takeDamage(salamander.getAttackDamage());
    unname.beRepaired(1);
    return (0);
}
