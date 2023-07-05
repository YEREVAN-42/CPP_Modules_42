/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:43:45 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/05 17:27:54 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::info()
{
	std::cout << BOLDGREEN << "[ INFO ]" << std::endl 
			<< "I cannot believe adding extra bacon costs more money."
			<< " You didn’t put enough bacon in my burger!"
			<< " If you did, I wouldn’t be asking for more!"
			<< RESET << std::endl;
}

void Harl::debug()
{
	std::cout << BOLDMAGENTA << "[ DEBUG ]" << std::endl
			<< "I love having extra bacon for my"
			<< " 7XL-double-cheese-triple-pickle-special- ketchup burger."
			<< " I really do!"
			<< RESET << std::endl;
}

void Harl::error()
{
	std::cout << BOLDRED << "[ ERROR ]" << std::endl
			<< "This is unacceptable! I want to speak to the manager now."
			<< RESET << std::endl;
}

void Harl::warning()
{
	std::cout << BOLDYELLOW << "[ WARNING ]" << std::endl
			<< "I think I deserve to have some extra bacon for free."
			<< " I’ve been coming for years whereas you started working"
			<< " here since last month."
			<< RESET << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*funPoint[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};
	std::string prototype[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = -1;
	while (++i < 4 && level.compare(prototype[i]))
		;
	if (i == 4) {
		std::cerr << BOLDRED
			<< "[ Probably complaining about insignificant problems ]"
			<< RESET << std::endl;
		return ;
	}
	switch (i) {
		case 0:
			(this->*funPoint[0])();
		case 1:
			(this->*funPoint[1])();
		case 2:
			(this->*funPoint[2])();
		case 3:
			(this->*funPoint[3])();
	}
}
