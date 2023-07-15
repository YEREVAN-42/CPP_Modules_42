/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:35:49 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/15 14:50:07 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
void    Show()
{
    std::cout << BOLDBLUE << "MY AWESOME" << std::endl
			<< "PHONEBOOK" << BOLDGREEN << std::endl << std::endl
			<< "1. ADD" << std::endl
			<< "2. SEARCH" << std::endl
			<< "3. EXIT" << WHITE << std::endl << std::endl;
}

int main()
{
	std::string cmd;
	PhoneBook   pb;

	Show();
	while (1)
	{
		std::cout << CYAN << "Enter " << GREEN 
		<< "command " << CYAN << "from up " << WHITE;
		getline(std::cin, cmd);
		if (std::cin.eof()) {
			break ;
		}
		if (cmd == "ADD" || cmd == "1") {
			pb.Add();
		} else if (cmd == "SEARCH" || cmd == "2") {
			pb.Search();
		} else if (cmd == "EXIT" || cmd == "3") {
			break ;
		} else {
			std::cout << RED << "❌ WRONG COMMAND" << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << MAGENTA << "Phone Book closed" << std::endl;
	return 0;
}
