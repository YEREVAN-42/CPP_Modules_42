/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:55:57 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 19:00:37 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
	AMateria();
	AMateria(const std::string& materia);
	AMateria(const AMateria& other);
	virtual ~AMateria();
	
	AMateria& operator=(const AMateria& other);

public:
	const std::string& getType() const; //Returns the materia type

public:
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) const = 0;
	// virtual void use(ICharacter& target);

protected:
	const std::string mmateria;
};

#endif
