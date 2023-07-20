/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:15:55 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/19 20:47:00 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <string>
# include <iostream>
# include <exception>

const int MAX = 1;
const int MIN = 150;

class Bureaucrat
{
private:
	Bureaucrat();

public:
	Bureaucrat(const std::string& name);
	Bureaucrat(const std::string& name, int grade) throw();
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	
	Bureaucrat& operator=(const Bureaucrat& other);

public:
	const std::string& getName() const;
	int                getGrade() const;
	
public:
	void increment() throw();
	void decrement() throw();
	
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
