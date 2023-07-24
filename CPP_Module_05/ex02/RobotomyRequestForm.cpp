/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:44:08 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/24 21:24:53 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {	}

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", RRF_Exec, RRF_Sign), mtarget("")
{	}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", RRF_Exec, RRF_Sign), mtarget(target)
{	}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm("RobotomyRequestForm", RRF_Exec, RRF_Sign), mtarget(other.mtarget)
{	}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw AForm::MyException("Bureaucrat is not authorized to sign");
	} else if (this->isSigned() == false) {
		throw AForm::MyException("Not signed forms cannot be executed!");
	}

	// system("say Oh, no! Oh my GOD!");
	std::srand(std::time(NULL));
	if (std::rand() % 100 < 50) {
		std::cout << mtarget << MAGENTA << " robotomized not successfully" << std::endl;
	} else {
		std::cout << mtarget << MAGENTA << " robotomized successfully" << std::endl;
	}
}
