/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:23:56 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/15 19:41:36 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& other);
	virtual ~Cat();
	
	Cat& operator=(const Cat& other);

public:
	virtual void makeSound() const;
};

#endif