/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 19:54:11 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/28 20:39:32 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __ARRAY_TPP__
# define __ARRAY_TPP__

#include "Array.hpp"

template <class T>
Array<T>::Array() : marray(NULL), msize(0) {	}
template <class T>
Array<T>::Array(std::size_t n) : marray(new T[n]()), msize(n) {	}
template <class T>
Array<T>::Array(const Array& other)
: marray(new T[other.msize]()), msize(other.msize)
{
	for (std::size_t i = 0; i < msize; ++i) {
		marray[i] = other.marray[i];
	}
}
template <class T>
Array<T>::~Array()
{
	msize = 0;
	delete[] marray;
	marray = NULL;
}

template <class T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other) {
		return *this;
	}
	if (marray != NULL) {
		delete[] marray;
	}
	marray = new T[other.msize]();
	for (std::size_t i = 0; i < other.msize; ++i) {
		marray[i] = other.marray[i];
	}
	msize = other.msize;
	return *this;
}

template <class T>
std::size_t Array<T>::size() const { return msize; }

template <class T>
const T& Array<T>::operator[](std::size_t pos) const 
{
	if (pos >= msize) {
		throw std::out_of_range("❌ Out of range");
	}
	return marray[pos];
}
template <class T>
T& Array<T>::operator[](std::size_t pos)
{
	return (const_cast<T&>(
		static_cast<const Array<T>&>(*this)[pos]
	));
}

#endif
