/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:59:38 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/22 21:10:28 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : mname(""), mexecGrade(1), msignedGrade(1), msigned(false) { }
Form::~Form() { }
Form::Form(const Form& other)
: mname(other.mname), mexecGrade(other.mexecGrade),
	msignedGrade(other.msignedGrade), msigned(other.msigned)
{ }
Form::Form(const std::string& name, int execGrade, int signedGrade)
: mname(name), mexecGrade(execGrade), msignedGrade(signedGrade), msigned(false)
{
	if (mexecGrade < MAX || msignedGrade < MAX) {
		throw GradeTooHighException();
	}
	if (mexecGrade > MIN || msignedGrade > MIN) {
		throw GradeTooLowException();
	}
}

Form& Form::operator=(const Form& other)
{
	if (this == &other) {
		return *this;
	}
	this->msigned = other.msigned;
	return *this;
}

const std::string& Form::getName() const { return mname; }
bool               Form::isSigned() const { return msigned; }
int                Form::getSignedGrade() const { return msignedGrade; }
int                Form::getExecuteGrade() const { return mexecGrade; }

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= msignedGrade) {
		msigned = true;
	} else {
		throw MyException("Bureaucrat is not authorized to sign the AForm!");
	}
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << BOLDCYAN;
	out << "Form: " << form.getName() << std::endl;
	out << "Signed: " << (form.isSigned() ? "True" : "False") << std::endl;
	out << "GradeToSign: " << form.getSignedGrade() << std::endl;
	out << "GradeToExecute: " << form.getExecuteGrade();
	out << RESET;

	return out;
}

//		--------------------------------------------------------------------------

const char* Form::GradeTooHighException::what() const throw()
{ return "The grade is higher than the maximum possible grade (1)."; }

const char* Form::GradeTooLowException::what() const throw()
{ return "The grade is lower than the minimum possible grade (150)."; }

Form::MyException::MyException(const char* message) : mmessage(message) { }

const char* Form::MyException::what() const throw()
{ return this->mmessage; }