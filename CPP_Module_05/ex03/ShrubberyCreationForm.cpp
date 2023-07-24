/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:44:12 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/25 01:16:06 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {	}

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", SCF_Exec, SCF_Sign), mtarget("")
{	}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", SCF_Exec, SCF_Sign), mtarget(target)
{	}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm("ShrubberyCreationForm", SCF_Exec, SCF_Sign), mtarget(other.mtarget)
{	}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw AForm::MyException("Bureaucrat is not authorized to sign");
	} else if (this->isSigned() == false) {
		throw AForm::MyException("Not signed forms cannot be executed!");
	}

	const std::string fileName = mtarget + "_shrubbery";
	std::ofstream out(fileName.c_str());
	
	if (!out.is_open()) {
		throw AForm::MyException("Couldn't open the file ❗️");
	}
	out	<< TREE << std::endl;
	out.close();
}
