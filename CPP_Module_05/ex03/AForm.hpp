/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:19:30 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/24 20:17:34 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __AFORM_HPP__
# define __AFORM_HPP__

# include <string>
# include <iostream>
# include <exception>

# include "Colors.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	AForm();
public:
	AForm(const std::string& name, int execGrade, int signedGrade);
	AForm(const AForm& other);
	virtual ~AForm();
	
	AForm& operator=(const AForm& other);
	
public:
	const std::string& getName() const;
	bool               isSigned() const; // getSigned() function
	int                getSignedGrade() const;
	int                getExecuteGrade() const;

public:
	void beSigned(const Bureaucrat& bureaucrat);

public:
	virtual void execute(const Bureaucrat& executor) const = 0;

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

protected:
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

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif
