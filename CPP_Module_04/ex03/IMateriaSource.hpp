/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:45:25 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 19:02:04 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __IMATERIALSOURCE_HPP__
# define __IMATERIALSOURCE_HPP__

# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}

public:
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif