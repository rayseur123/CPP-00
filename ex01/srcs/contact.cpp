/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:16:07 by njooris           #+#    #+#             */
/*   Updated: 2025/12/05 12:55:36 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "contact.h"

void		Contact::set_first_name(std::string str)
{
	first_name = str;
}

void		Contact::set_last_name(std::string str)
{
	last_name = str;
}

void		Contact::set_nick_name(std::string str)
{
	nick_name = str;	
}

void		Contact::set_phone_number(std::string str)
{
	phone_number = str;
}

void		Contact::set_darkest_secret(std::string str)
{
	darkest_secret = str;
}

std::string	Contact::get_first_name(void)
{
	return (first_name);
}

std::string	Contact::get_last_name(void)
{
	return (last_name);
}

std::string	Contact::get_nick_name(void)
{
	return (nick_name);
}

std::string	Contact::get_phone_number(void)
{
	return (phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (darkest_secret);
}