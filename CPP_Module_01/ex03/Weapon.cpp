/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:25:32 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/04 22:33:44 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
: mtype(type)
{	}

Weapon::~Weapon()
{	}

const std::string& Weapon::GetType() const
{
	return this->mtype;
}

void Weapon::SetType(const std::string& type)
{
	this->mtype = type;
}
