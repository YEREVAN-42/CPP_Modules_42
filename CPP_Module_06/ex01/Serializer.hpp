/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:59:00 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/27 18:32:02 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __SERIALIZER_HPP__
# define __SERIALIZER_HPP__


# include <iostream>
# include <stdint.h>

struct Data
{
	int value;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& other);
	~Serializer();

	Serializer& operator=(const Serializer& other);
	
public:
	static uintptr_t serialize(Data*);
	static Data*     deserialize(uintptr_t);
};

#endif
