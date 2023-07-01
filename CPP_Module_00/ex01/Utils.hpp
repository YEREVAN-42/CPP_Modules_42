/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:20:49 by khovakim          #+#    #+#             */
/*   Updated: 2023/06/30 16:58:21 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>

const std::string RED         = "\033[31m"; // Red
const std::string CYAN        = "\033[36m"; // Cyan
const std::string BLUE        = "\033[34m"; // Blue
const std::string RESET       = "\033[0m";
const std::string BLACK       = "\033[30m"; // Black
const std::string GREEN       = "\033[32m"; // Green
const std::string WHITE       = "\033[37m"; // White
const std::string YELLOW      = "\033[33m"; // Yellow
const std::string MAGENTA     = "\033[35m"; // Magenta
const std::string BOLDRED     = "\033[1m\033[31m"; // Bold Red
const std::string BOLDBLUE    = "\033[1m\033[34m"; // Bold Blue
const std::string BOLDCYAN    = "\033[1m\033[36m"; // Bold Cyan
const std::string BOLDBLACK   = "\033[1m\033[30m"; // Bold Black
const std::string BOLDGREEN   = "\033[1m\033[32m"; // Bold Green
const std::string BOLDWHITE   = "\033[1m\033[37m"; // Bold White
const std::string BOLDYELLOW  = "\033[1m\033[33m"; // Bold Yellow
const std::string BOLDMAGENTA = "\033[1m\033[35m"; // Bold Magenta

bool OnlyDigits(const std::string& str);
bool OnlyLetters(const std::string& str);

std::string ReSize(std::string str);

void Input(std::string& str, const std::string& messige);
void Input(std::string& str, const std::string& messige,\
		bool (*checker)(const std::string&));

#endif
