/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:29:04 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/17 16:37:35 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <iostream>
# include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& other);
	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& other);

public:
	const std::string getType() const;
	void              makeSound() const;

protected:
	std::string mtype;
};

#endif
