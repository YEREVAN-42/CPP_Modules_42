/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:28:12 by khovakim          #+#    #+#             */
/*   Updated: 2023/06/29 18:56:04 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void PrintStr(const char* str)
{
	while (*str != '\0') {
		std::cout << static_cast<char>(std::toupper(static_cast<int>(*str)));
		++str;
	}
}

int main(int argc, const char* argv[])
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < argc; ++i) {
			PrintStr(argv[i]);
		}
		std::cout << std::endl;
	}
	return 0;
}
