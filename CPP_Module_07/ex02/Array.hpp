/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:35:40 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/28 20:38:02 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __ARRAY_HPP__
# define __ARRAY_HPP__

# include <exception>
# include <iostream>

template <class T>
class Array
{
public:
	Array();
	Array(std::size_t n);
	Array(const Array& other);
	~Array();

	Array& operator=(const Array& other);

public:
	std::size_t size() const;
	
public:
	const T& operator[](std::size_t pos) const;
	T&       operator[](std::size_t pos);

private:
	T*          marray;
	std::size_t msize;
};

# include "Array.tpp"

#endif
