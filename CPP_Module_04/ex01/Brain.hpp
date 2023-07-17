/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:13:33 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/17 17:28:59 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>
# include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	Brain& operator=(const Brain& other);

public:
	const std::string& operator[](std::size_t pos) const;
	std::string&       operator[](std::size_t pos);

private:
	std::string mideas[100];
};

#endif
