/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:24 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/25 17:14:31 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

# include "Colors.hpp"

# include <string>
# include <sstream>
# include <iostream>

class ScalarConverter
{
public:
	static void convert(const std::string&);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();

	ScalarConverter& operator=(const ScalarConverter& other);

private:
	static bool isInt(const std::string&);
	static bool isChar(const std::string&);
	static bool isFloat(const std::string&);
	static bool isDouble(const std::string&);

	static void convertInt(const std::string&);
	static void convertChar(const std::string&);
	static void convertFloat(const std::string&);
	static void convertDouble(const std::string&);
};

#endif
