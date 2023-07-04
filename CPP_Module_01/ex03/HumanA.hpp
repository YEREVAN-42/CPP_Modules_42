/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:36:58 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/04 22:52:47 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __HUMANA_HPP__
# define __HUMANA_HPP__

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const std::string& name, const Weapon& weapon);
		~HumanA();

	public:
		void attack() const;
	
	private:
		std::string mname;
		Weapon&     mweapon;
};

#endif
