/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:15:55 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/22 21:10:51 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <string>
# include <iostream>
# include <exception>

# include "Form.hpp"
# include "Colors.hpp"

const int MAX = 1;
const int MIN = 150;

class Form;

class Bureaucrat
{
private:
	Bureaucrat();

public:
	Bureaucrat(const std::string& name);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	
	Bureaucrat& operator=(const Bureaucrat& other);

public:
	const std::string& getName() const;
	int                getGrade() const;
	
public:
	void increment();
	void decrement();
	
public:
	void signForm(Form& form) const;
	
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
	
private:
	const std::string mname;
	int               mgrade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
