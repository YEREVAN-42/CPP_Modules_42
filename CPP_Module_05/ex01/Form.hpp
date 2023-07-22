/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:19:30 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/22 21:07:54 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __FORM_HPP__
# define __FORM_HPP__

# include <string>
# include <iostream>
# include <exception>

# include "Colors.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	Form();
public:
	Form(const std::string& name, int execGrade, int signedGrade);
	Form(const Form& other);
	~Form();
	
	Form& operator=(const Form& other);
	
public:
	const std::string& getName() const;
	bool               isSigned() const; // getSigned() function
	int                getSignedGrade() const;
	int                getExecuteGrade() const;

public:
	void beSigned(const Bureaucrat& bureaucrat);

private:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class MyException : public std::exception
	{
	public:
		MyException(const char* message);
	
	public:
		const char* what() const throw();
	
	private:
		const char* mmessage;
	};

private:
	const std::string mname;
	const int         mexecGrade;
	const int         msignedGrade;

	bool msigned;
};

std::ostream& operator<<(std::ostream& out, const Form& AForm);

#endif
