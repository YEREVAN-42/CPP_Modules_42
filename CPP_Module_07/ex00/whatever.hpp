/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:05:19 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/28 17:05:20 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __WHATEVER_HPP__
# define __WHATEVER_HPP__

template <typename T>
void swap(T& a, T& b)
{
	T c;

	c = a;
	a = b;
	b = c;
}

template <typename T>
T min(const T& a, const T& b) { return a < b ? a : b; }
template <typename T>
T max(const T& a, const T& b) { return a > b ? a : b; }

#endif
