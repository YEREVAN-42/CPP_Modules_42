/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:55:55 by khovakim          #+#    #+#             */
/*   Updated: 2023/06/29 20:10:33 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::SetFirstName(const std::string& firstName)
{
	this->mfirstName = firstName;
}

void Contact::SetLastName(const std::string& lastName)
{
	this->mlastName = lastName;
}

void Contact::SetNickName(const std::string& nickName)
{
	this->mnickName = nickName;
}

void Contact::SetPhone(const std::string& phone)
{
	this->mphone = phone;
}

void Contact::SetSecret(const std::string& secret)
{
	this->msecret = secret;
}

std::string GetFirstName() const
{
	return this->mfirstName;
}

std::string GetLastName() const
{
	return this->mlastName;
}

std::string GetNickName() const
{
	return this->mnickName;
}

std::string GetPhone() const
{
	return this->mphone;
}

std::string GetSecret() const
{
	return this->msecret;
}

