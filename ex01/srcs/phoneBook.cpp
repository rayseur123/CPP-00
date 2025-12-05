/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:00:56 by njooris           #+#    #+#             */
/*   Updated: 2025/12/05 14:39:09 by njooris          ###   ########.fr       */
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
	if (index_contact < 7)
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

void	PhoneBook::display_contact(int i)
{
	std::cout << std::setw(10) << i ;
	std::cout << "|";
	std::cout << std::setw(10) << dot_manage(list_of_contact[i - 1].get_first_name());
	std::cout << "|";
	std::cout << std::setw(10) << dot_manage(list_of_contact[i - 1].get_last_name());
	std::cout << "|";
	std::cout << std::setw(10) << dot_manage(list_of_contact[i - 1].get_nick_name());
	std::cout << "|\n";
}

void	PhoneBook::display_contacts()
{
	std::cout << std::setw(10) << "ID" ;
	std::cout << "|";
	std::cout << std::setw(10) << "First Name";
	std::cout << "|";
	std::cout << std::setw(10) << "Last Name";
	std::cout << "|";
	std::cout << std::setw(10) << "Nick Name";
	std::cout << "|\n";
	for (size_t i = 0; i < nb_contact; i++)
		display_contact(i + 1);
}

void	PhoneBook::exit_prompt()
{
	std::string	user_line;

	std::cout << "Entrez un id pour voir un user" << "\n";
	std::getline(std::cin, user_line);
	while (user_line != "EXIT")
	{
		if (is_number(user_line)
			&& atoi(user_line.c_str()) <= (int)nb_contact
			&& atoi(user_line.c_str()) > 0)
			display_contact(atoi(user_line.c_str()));
		else
			std::cout << "Wrong id\n";
		std::getline(std::cin, user_line);
	}	
}

void	PhoneBook::search_contact()
{
	display_contacts();
	exit_prompt();
}
