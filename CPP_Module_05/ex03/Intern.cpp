/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:33:12 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/25 02:00:40 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {	}
Intern::Intern(const Intern& other) { (void)other; }
Intern::~Intern() {	}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeRobotomyRequest(const std::string &target) const { return new RobotomyRequestForm(target); }
AForm* Intern::makeShrubberyCreation(const std::string &target) const { return new ShrubberyCreationForm(target); }
AForm* Intern::makePresidentialPardon(const std::string &target) const { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	AForm* (Intern::*forms[3])(const std::string&) const = {
		&Intern::makeRobotomyRequest,
		&Intern::makeShrubberyCreation,
		&Intern::makePresidentialPardon
	};

	std::string formName[3];
	formName[0] = "robotomy request";
	formName[1] = "shrubbery creation";
	formName[2] = "presidential pardon";

	for (int i = 0; i < 3; ++i) {
		if (name == formName[i]) {
			return ((this->*forms[i])(target));
		}
	}

	std::cout << RED << "Intern was requested an unknown form" << RESET << std::endl;

	return NULL;
}
