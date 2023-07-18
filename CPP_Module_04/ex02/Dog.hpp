/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:36:16 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/17 17:48:26 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& other);
	virtual ~Dog();

	Dog& operator=(const Dog& other);

public:
	virtual void makeSound() const;

private:
	Brain* mbrain;
};

#endif
