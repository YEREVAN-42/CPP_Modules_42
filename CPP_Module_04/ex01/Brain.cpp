/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:26:00 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/18 20:58:28 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{ std::cout << "Default constructor called for Brain" << std::endl; }

Brain::~Brain()
{ std::cout << "Destructor called for Brain" << std::endl; }

Brain::Brain(const Brain& other)
{
	for (size_t i = 0; i < 100; ++i) {
		this->mideas[i] = other.mideas[i];
	}
	std::cout << "Copy constructor called for Brain" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Copy assignment operator called for Brain" << std::endl;
	if (this == &other) {
		return *this;
	}
	for (size_t i = 0; i < 100; ++i) {
		this->mideas[i] = other.mideas[i];
	}
	return *this;
}

std::string& Brain::operator[](std::size_t pos)
{ return this->mideas[pos]; }

const std::string& Brain::operator[](std::size_t pos) const
{ return this->mideas[pos]; }
