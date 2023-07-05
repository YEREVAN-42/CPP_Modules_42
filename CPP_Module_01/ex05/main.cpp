/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:20:09 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/05 17:26:10 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl		man;
	std::string	input;

	while (true)
	{
		getline(std::cin, input);
		if (input.empty())
			return(1);
		man.complain(input);
	}
}