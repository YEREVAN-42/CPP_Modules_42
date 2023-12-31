/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:34:29 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/22 16:35:34 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() { }
Bureaucrat::~Bureaucrat() { }
Bureaucrat::Bureaucrat(const std::string& name) : mname(name), mgrade(100) { }
Bureaucrat::Bureaucrat(const Bureaucrat& other) : mname(other.mname), mgrade(other.mgrade) { }
Bureaucrat::Bureaucrat(const std::string& name, int grade)
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
	this->mgrade = other.mgrade;
	return *this;
}

int Bureaucrat::getGrade() const { return mgrade; }
const std::string& Bureaucrat::getName() const { return mname; }

void Bureaucrat::increment()
{
	if (this->mgrade == MAX) {
		throw GradeTooHighException();
	}
	--mgrade;
}

void Bureaucrat::decrement()
{
	if (this->mgrade == MIN) {
		throw GradeTooLowException();
	}
	++mgrade;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << BOLDCYAN
		<< bureaucrat.getName() << "'s grade is " << bureaucrat.getGrade()
		<< RESET;
	
	return out;
}

//		--------------------------------------------------------------------------

const char* Bureaucrat::GradeTooHighException::what() const throw()
{ return "The grade is higher than the maximum possible grade (1)."; }

const char* Bureaucrat::GradeTooLowException::what() const throw()
{ return "The grade is lower than the minimum possible grade (150)."; }

