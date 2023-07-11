/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:18:13 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/11 18:48:41 by khovakim         ###   ########.fr       */
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
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& other);

public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
private:
	std::string  mname;
	unsigned int mhitPoint;
	unsigned int menergyPoint;
	unsigned int mattackDamage;
};

#endif
