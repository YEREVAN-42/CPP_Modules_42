/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:35:49 by khovakim          #+#    #+#             */
/*   Updated: 2023/06/30 17:02:55 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string cmd;
	PhoneBook   pb;

	while (1)
	{
	std::cout << CYAN << "Enter " << GREEN 
		<< "command " << CYAN << "from up " << WHITE;
		getline(std::cin, cmd);
		if (std::cin.eof()) {
			break ;
		}
		if (cmd == "ADD" || cmd == "add") {
			pb.Add();
		} else if (cmd == "SEARCH" || cmd == "search") {
			pb.Search();
		} else if (cmd == "EXIT" || cmd == "exit") {
			break ;
		} else {
			std::cout << RED << "❌ WRONG COMMAND" << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << MAGENTA << "Phone Book closed" << std::endl;
	return 0;
}
