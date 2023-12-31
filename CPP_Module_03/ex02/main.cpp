/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:48:19 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/14 13:30:03 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap salamander("Salamander");
	ClapTrap unname;
    ScavTrap jhon("Jhon");
    FragTrap aram("Aram");
    
    salamander.setAttackDamage(20);
    salamander.attack("Zombie");
    salamander.takeDamage(2);
    salamander.beRepaired(1);

	unname.attack("Zombie");
    unname.takeDamage(salamander.getAttackDamage());
    unname.beRepaired(1);

    jhon.guardGate();
    jhon.attack("Zombie");
    jhon.takeDamage(2);
    jhon.beRepaired(1);
    
    aram.highFivesGuys();
    aram.attack("Zombie");
    aram.takeDamage(2);
    aram.beRepaired(1);
    
    return (0);
}
