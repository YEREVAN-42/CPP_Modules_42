/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:20:09 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/05 17:26:23 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, const char* argv[])
{
	Harl		man;

	if (argc != 2) {
		std::cerr << BOLDRED << "wrong number of arguments" << RESET << std::endl;
		return (1);
	}
	man.complain(argv[1]);
}