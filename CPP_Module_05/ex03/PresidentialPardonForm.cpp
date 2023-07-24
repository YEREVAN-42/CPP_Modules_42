/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:07:08 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/24 21:14:20 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm()
{	}

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", PPF_Exec, PPF_Sign), mtarget("")
{	}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", PPF_Exec, PPF_Sign), mtarget(target)
{	}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm("PresidentialPardonForm", PPF_Exec, PPF_Sign), mtarget(other.mtarget)
{	}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw AForm::MyException("Bureaucrat is not authorized to sign");
	} else if (this->isSigned() == false) {
		throw AForm::MyException("Not signed forms cannot be executed!");
	}

	std::cout << BOLDMAGENTA << mtarget << " has been pardoned by Zafod Beeblebrox." << RESET << std::endl;
}
