/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:14:24 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/27 13:49:02 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

# include "Colors.hpp"

# include <cmath>
# include <string>
// # include <cstdlib>
# include <limits>
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
	static bool isFinite(float);
	static bool isFinite(double);

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
