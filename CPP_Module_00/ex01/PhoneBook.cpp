/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:12:18 by khovakim          #+#    #+#             */
/*   Updated: 2023/06/30 17:18:43 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: mindex(0), mcurrent(0)
{  }

void PhoneBook::Add()
{
	std::string str;
	Contact     contact;

	Input(str, "First Name: ", OnlyLetters);
	contact.SetFirstName(str);
	Input(str, "Last Name: ", OnlyLetters);
	contact.SetLastName(str);
	Input(str, "Phone Number: ", OnlyDigits);
	contact.SetPhone(str);
	Input(str, "Nick Name: ");
	contact.SetNickName(str);
	Input(str, "Darkest Secret: ");
	contact.SetSecret(str);

	this->mcontact[mcurrent % 8] = contact;
	++mcurrent;
	if (mindex <= 8) {
		mindex = mcurrent;
	}
	std::cout << YELLOW << "*------ADDED-------*" << std::endl;
}

void PhoneBook::Show()
{
	std::cout << MAGENTA << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|";
	std::cout << std::endl;
	for (std::size_t i = 0; i < mindex; ++i) {
		std::cout
        << "|" << std::setw(10) << i
        << "|" << std::setw(10) << ReSize(this->mcontact[i].GetFirstName())
        << "|" << std::setw(10) << ReSize(this->mcontact[i].GetLastName())
        << "|" << std::setw(10) << ReSize(this->mcontact[i].GetNickName())
        << "|" << std::endl;
	}
}

void PhoneBook::Search()
{
	this->Show();
	std::cout << GREEN << "Enter the index " << WHITE;
	std::size_t index;
    std::cin >> index;
	if (std::cin.fail()) {
		std::cout << RED << "TRY AGAIN " << WHITE << std::endl;
	} else {
		if (index < this->mindex) {
			std::cout << "First Name: "
				<< this->mcontact[index].GetFirstName() << std::endl;
			std::cout << "Last Name: "
				<< this->mcontact[index].GetLastName() << std::endl;
			std::cout << "Nick Name: "
				<< this->mcontact[index].GetNickName() << std::endl;
			std::cout << "Phone Number: "
				<< this->mcontact[index].GetPhone() << std::endl;
			std::cout << "Darkest Secret: "
				<< this->mcontact[index].GetSecret() << std::endl;
		} else {
			std::cout << RED << "TRY AGAIN " << WHITE << std::endl;
		}
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

