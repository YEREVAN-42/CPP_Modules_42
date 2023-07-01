/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:41:27 by khovakim          #+#    #+#             */
/*   Updated: 2023/06/30 16:45:47 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
		//		Setter
		void SetFirstName(const std::string& firstName);
		void SetLastName(const std::string& lastName);
		void SetNickName(const std::string& NickName);
		void SetPhone(const std::string& phone);
		void SetSecret(const std::string& secret);

		//		Getter
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetNickName() const;
		std::string GetPhone() const;
		std::string GetSecret() const;

	private:
		std::string mfirstName;
		std::string mlastName;
		std::string mnickName;
		std::string mphone;
		std::string msecret;
};

#endif
