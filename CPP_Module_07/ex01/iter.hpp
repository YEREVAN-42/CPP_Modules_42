/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:17:48 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/28 17:17:52 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __ITER_HPP__
# define __ITER_HPP__

# include <iostream>

template <typename T>
void print(const T& arg) { std::cout << arg << std::endl; }

template <typename T>
void iter(T* arr, int len, void (*f)(const T&))
{
	for (int i = 0; i < len; ++i) {
		f(arr[i]);
	}
}


#endif
