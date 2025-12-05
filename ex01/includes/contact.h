/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:54:37 by njooris           #+#    #+#             */
/*   Updated: 2025/12/05 12:52:16 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_H
# define Contact_H
#include <string>

class	Contact
{
	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nick_name;
		std::string		phone_number;
		std::string		darkest_secret;
	public:
		void		set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_nick_name(std::string str);
		void		set_phone_number(std::string str);
		void		set_darkest_secret(std::string str);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nick_name(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);
};

#endif