/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:11:32 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/04 22:38:08 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __WEAPON_HPP__
# define __WEAPON_HPP__

# include <string>

class Weapon
{
	public:
		Weapon(const std::string& type);
		~Weapon();

	public:
		const std::string& GetType() const;
		void SetType(const std::string& type);
		
	private:
		std::string mtype;
};

#endif
