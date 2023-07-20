/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:34:29 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/20 15:55:24 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() { }
Bureaucrat::~Bureaucrat() { }
Bureaucrat::Bureaucrat(const std::string& name) : mname(name), mgrade(100) { }
Bureaucrat::Bureaucrat(const Bureaucrat& other) : mname(other.mname), mgrade(other.mgrade) { }
Bureaucrat::Bureaucrat(const std::string& name, int grade) throw()
: mname(name), mgrade(grade)
{
	if (this->mgrade < MAX) {
		throw GradeTooHighException();
	}
	if (this->mgrade > MIN) {
		throw GradeTooLowException();
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other) {
		return *this;
	}
	static_cast<std::string>(this->mname) = other.mname;
	this->mgrade = other.mgrade;
	return *this;
}

int Bureaucrat::getGrade() const { return mgrade; }
const std::string& Bureaucrat::getName() const { return mname; }

void Bureaucrat::increment() throw()
{
	if (this->mgrade == MAX) {
		throw GradeTooHighException();
	}
	--mgrade;
}

void Bureaucrat::decrement() throw()
{
	if (this->mgrade == MIN) {
		throw GradeTooLowException();
	}
	++mgrade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << "'s grade is " << bureaucrat.getGrade();
	return out;
}

//		--------------------------------------------------------------------------

const char* Bureaucrat::GradeTooHighException::what() const throw()
{ return "Grade is too high!"; }

const char* Bureaucrat::GradeTooLowException::what() const throw()
{ return "Grade is too low!"; }

