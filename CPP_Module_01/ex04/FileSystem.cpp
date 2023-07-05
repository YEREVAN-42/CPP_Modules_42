/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileSystem.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:04:14 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/05 14:47:30 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileSystem.hpp"

FileSystem::FileSystem(const std::string& fileName)
: minFile(fileName), moutFile(fileName + ".replace")
{	}

FileSystem::~FileSystem()
{
	this->minFile.close();
	this->moutFile.close();
}

void FileSystem::replace(const std::string& str1, const std::string& str2)
{

	std::string content;
	std::size_t pos = 0;
	std::size_t index = 0;

	if (getline(this->minFile, content, '\0')) {
		while (1) {
			pos = content.find(str1, index);
			if (pos == std::string::npos) {
				break ;
			}
			content.erase(pos, str1.size());
			content.insert(pos, str2);
			index = pos + str1.size();
		}
		this->moutFile << content;
	} else {
		std::cout << BOLDRED << "❌ Empty File" << RESET << std::endl;
		exit(1);
	}
}
