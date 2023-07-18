/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:39 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 19:00:54 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"


class Character : public ICharacter
{
public:
	Character();
	Character(const std::string& name);
	Character(const Character& other);
	virtual ~Character();

	Character& operator=(const Character& other);
	
public:
	virtual const std::string& getName() const;

	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:
	const std::string mname;
	std::size_t       msize;
	AMateria*         minventory[4];
};

#endif
