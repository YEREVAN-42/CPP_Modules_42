/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:23:24 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/17 16:05:25 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>
# include <string>

class Animal
{
public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& other);
	virtual ~Animal();

	Animal& operator=(const Animal& other);

public:
	const std::string getType() const;
	virtual void      makeSound() const;

protected:
	std::string mtype;
};

#endif
