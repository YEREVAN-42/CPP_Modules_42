/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:36:58 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/04 23:24:24 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __HUMANB_HPP__
# define __HUMANB_HPP__

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string& name);
		~HumanB();

	public:
		void attack() const;
		void SetWeapon(Weapon& weapon);
	
	private:
		std::string mname;
		Weapon*     mweapon;
};

#endif
