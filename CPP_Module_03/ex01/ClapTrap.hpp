/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:18:13 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/11 20:44:06 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <string>
# include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	virtual ~ClapTrap();

	ClapTrap& operator=(const ClapTrap& other);

public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string  mname;
	unsigned int mhitPoint;
	unsigned int menergyPoint;
	unsigned int mattackDamage;
};

#endif
