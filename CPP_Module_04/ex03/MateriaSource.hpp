/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:08 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 19:02:20 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class	MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	~MateriaSource();

	MateriaSource	&operator=(const MateriaSource &other);

public:
	virtual void      learnMateria(AMateria *materia);
	virtual AMateria* createMateria(std::string const &type);

private:
	AMateria*   mmaterias[4];
	std::size_t msize;
};

#endif
