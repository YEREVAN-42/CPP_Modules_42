/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:59:38 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/22 21:03:55 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : mname(""), mexecGrade(1), msignedGrade(1), msigned(false) { }
AForm::~AForm() { }
AForm::AForm(const AForm& other)
: mname(other.mname), mexecGrade(other.mexecGrade),
	msignedGrade(other.msignedGrade), msigned(other.msigned)
{ }
AForm::AForm(const std::string& name, int execGrade, int signedGrade)
: mname(name), mexecGrade(execGrade), msignedGrade(signedGrade), msigned(false)
{
	if (mexecGrade < MAX || msignedGrade < MAX) {
		throw GradeTooHighException();
	}
	if (mexecGrade > MIN || msignedGrade > MIN) {
		throw GradeTooLowException();
	}
}

AForm& AForm::operator=(const AForm& other)
{
	if (this == &other) {
		return *this;
	}
	this->msigned = other.msigned;
	return *this;
}

const std::string& AForm::getName() const { return mname; }
bool               AForm::isSigned() const { return msigned; }
int                AForm::getSignedGrade() const { return msignedGrade; }
int                AForm::getExecuteGrade() const { return mexecGrade; }

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= msignedGrade) {
		msigned = true;
	} else {
		throw MyException("Bureaucrat is not authorized to sign the AForm!");
	}
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << BOLDCYAN;
	out << "AForm: " << AForm.getName() << std::endl;
	out << "Signed: " << (AForm.isSigned() ? "True" : "False") << std::endl;
	out << "GradeToSign: " << AForm.getSignedGrade() << std::endl;
	out << "GradeToExecute: " << AForm.getExecuteGrade();
	out << RESET;

	return out;
}

//		--------------------------------------------------------------------------

const char* AForm::GradeTooHighException::what() const throw()
{ return "The grade is higher than the maximum possible grade (1)."; }

const char* AForm::GradeTooLowException::what() const throw()
{ return "The grade is lower than the minimum possible grade (150)."; }

AForm::MyException::MyException(const char* message) : mmessage(message) { }

const char* AForm::MyException::what() const throw()
{ return this->mmessage; }