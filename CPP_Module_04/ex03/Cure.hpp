/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:19:15 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 19:01:17 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& other);
	virtual ~Cure();

	Cure& operator=(const Cure& other);
	
public:
	// virtual void use(ICharacter& target);
	virtual void use(ICharacter& target) const;
	virtual AMateria* clone() const;
};

#endif
