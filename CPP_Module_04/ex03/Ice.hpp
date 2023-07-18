/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:00:01 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 19:01:33 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& other);
	virtual ~Ice();

	Ice& operator=(const Ice& other);
	
public:
	// virtual void use(ICharacter& target);
	virtual void use(ICharacter& target) const;
	virtual AMateria* clone() const;
};

#endif
