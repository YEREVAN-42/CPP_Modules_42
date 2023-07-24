/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:40:43 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/25 01:40:47 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __INTERN_HPP__
# define __INTERN_HPP__

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern& operator=(const Intern& other);

public:
	AForm* makeForm(const std::string& name, const std::string& target) const;

private:
	AForm* makeRobotomyRequest(const std::string &target) const;
	AForm* makeShrubberyCreation(const std::string &target) const;
	AForm* makePresidentialPardon(const std::string &target) const;
};

#endif
