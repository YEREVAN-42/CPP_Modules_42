/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:39:52 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/05 14:51:00 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileSystem.hpp"

void CheckFilePath(const std::string& filePath)
{
	std::ifstream inFile(filePath);
	
	if (!inFile.is_open()) {
		std::cout << BOLDRED << "❌ No File" << RESET << std::endl;
		exit(1);
	}
	inFile.close();
}

int main(int ac, const char* av[])
{
	if (ac != 4) {
		std::cout << BOLDRED << "❌ Invalid input" << RESET <<std::endl;
	}
	CheckFilePath(av[1]);
	FileSystem file(av[1]);
	file.replace(av[2], av[3]);
	return 0;
}
