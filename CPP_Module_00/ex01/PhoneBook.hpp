/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:17:39 by khovakim          #+#    #+#             */
/*   Updated: 2023/07/01 16:39:50 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include "Utils.hpp"
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();

		void Add();
		void Search();
		void Show();

	private:
		Contact mcontact[8];
		std::size_t mindex;
		std::size_t mcurrent;
};

#endif
