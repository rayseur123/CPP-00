/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:16:07 by njooris           #+#    #+#             */
/*   Updated: 2025/12/12 14:47:47 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

void		Contact::set_first_name(std::string str)
{
	_first_name = str;
}

void		Contact::set_last_name(std::string str)
{
	_last_name = str;
}

void		Contact::set_nick_name(std::string str)
{
	_nick_name = str;	
}

void		Contact::set_phone_number(std::string str)
{
	_phone_number = str;
}

void		Contact::set_darkest_secret(std::string str)
{
	_darkest_secret = str;
}

std::string	Contact::get_first_name(void)
{
	return (_first_name);
}

std::string	Contact::get_last_name(void)
{
	return (_last_name);
}

std::string	Contact::get_nick_name(void)
{
	return (_nick_name);
}

std::string	Contact::get_phone_number(void)
{
	return (_phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (_darkest_secret);
}