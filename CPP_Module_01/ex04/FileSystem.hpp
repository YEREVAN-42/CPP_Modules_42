/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileSystem.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:53:20 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/05 14:40:26 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __FILESYSTEM_HPP__
# define __FILESYSTEM_HPP__

# include <iostream>
# include <fstream>
# include <string>

const std::string RESET       = "\033[0m";
const std::string BOLDRED     = "\033[1m\033[31m"; // Bold Red

class FileSystem
{
	public:
		FileSystem(const std::string& fileName);
		~FileSystem();
	
	public:
		void replace(const std::string& str1, const std::string& str2);

	private:
		std::ifstream minFile;
		std::ofstream moutFile;
};

#endif
