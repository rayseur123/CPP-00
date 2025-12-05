/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:00:56 by njooris           #+#    #+#             */
/*   Updated: 2025/12/05 13:21:20 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.h"
#include "phoneBook.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <stdio.h>

PhoneBook::PhoneBook()
{
	index_contact = 0;
	nb_contact = 0;
}

void	PhoneBook::add_contact(Contact contact)
{
	list_of_contact[index_contact] = contact;
	if (index_contact <= 7)
		index_contact++;
	else
		index_contact = 0;
	if (nb_contact < 8)
		nb_contact++;
}

bool	is_number(std::string str)
{
	for (size_t i = 0; i < str.size();)
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	PhoneBook::build_contact()
{
	Contact 	contact;
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string darkest_secret;

	while(first_name.empty())
	{
		std::cout << "fist name :\n";
		getline(std::cin, first_name);
	}
	while (last_name.empty())
	{
		std::cout << "last name :\n";
		getline(std::cin, last_name);
	}
	while (nick_name.empty())
	{
		std::cout << "nick name :\n";
		getline(std::cin, nick_name);
	}
	std::cout << "phone number :\n";
	getline(std::cin, phone_number);
	while (phone_number.empty() || !is_number(phone_number))
	{
		std::cout << "phone NUMBER :\n";
		getline(std::cin, phone_number);
	}
	while (darkest_secret.empty())
	{
		std::cout << "darkest secret :\n";
		getline(std::cin, darkest_secret);
	}	
	contact.set_first_name(first_name);
	contact.set_last_name(last_name);
	contact.set_nick_name(nick_name);
	contact.set_phone_number(phone_number);
	contact.set_darkest_secret(darkest_secret);
	add_contact(contact);
}

std::string	dot_manage(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) += '.');
	return (str.substr(0, 9));
}

void	PhoneBook::display_contact()
{
	for (size_t i = 0; i < nb_contact; i++)
	{
		std::cout << std::setw(10) << i + 1 ;
		std::cout << " | ";
		std::cout << std::setw(10) << dot_manage(list_of_contact[i].get_first_name());
		std::cout << " | ";
		std::cout << std::setw(10) << dot_manage(list_of_contact[i].get_last_name());
		std::cout << " | ";
		std::cout << std::setw(10) << dot_manage(list_of_contact[i].get_nick_name());
		std::cout << " |\n ";
	}
}

void	PhoneBook::search_contact()
{
	display_contact();
}
