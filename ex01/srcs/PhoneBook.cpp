/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:00:56 by njooris           #+#    #+#             */
/*   Updated: 2025/12/15 10:11:25 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <stdio.h>

PhoneBook::PhoneBook()
{
	_index_contact = 0;
	_nb_contact = 0;
}

void	PhoneBook::add_contact(Contact contact)
{
	_list_of_contact[_index_contact] = contact;
	if (_index_contact < 7)
		_index_contact++;
	else
		_index_contact = 0;
	if (_nb_contact < 8)
		_nb_contact++;
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

int		print_check_line(std::string *str, std::string str_print)
{
	std::cout << str_print << " :\n";
	while(getline(std::cin, *str) && str->empty())
		std::cout << str_print << " :\n";
	if (!std::cin)
		return (1);
	return (0);
}

int		print_check_phone(std::string *str, std::string str_print)
{
	std::cout << str_print << " :\n";
	while (getline(std::cin, *str) && (str->empty() || !is_number(*str)))
		std::cout << "phone NUMBER :\n";
	if (!std::cin)
		return (1);
	return (0);
}

int		PhoneBook::build_contact()
{
	Contact 	contact;
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string darkest_secret;

	if (print_check_line(&first_name, "first name"))
		return (1);
	if (print_check_line(&last_name, "last name"))
		return (1);
	if (print_check_line(&nick_name, "nick name"))
		return (1);
	if (print_check_phone(&phone_number, "phone number"))
		return (1);
	if (print_check_line(&darkest_secret, "darkest secret"))	
		return (1);
	contact.set_first_name(first_name);
	contact.set_last_name(last_name);
	contact.set_nick_name(nick_name);
	contact.set_phone_number(phone_number);
	contact.set_darkest_secret(darkest_secret);
	add_contact(contact);
	
	return (0);
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
	std::cout << std::setw(10) << dot_manage(_list_of_contact[i - 1].get_first_name());
	std::cout << "|";
	std::cout << std::setw(10) << dot_manage(_list_of_contact[i - 1].get_last_name());
	std::cout << "|";
	std::cout << std::setw(10) << dot_manage(_list_of_contact[i - 1].get_nick_name());
	std::cout << "|\n";
}

void	PhoneBook::display_contact_full(int i)
{
	std::cout << std::setw(10) << "- First Name : " << _list_of_contact[i - 1].get_first_name() << "\n";
	std::cout << std::setw(10) << "- Last Name : " << _list_of_contact[i - 1].get_last_name() << "\n";
	std::cout << std::setw(10) << "- Nick Name : " << _list_of_contact[i - 1].get_nick_name() << "\n";
	std::cout << std::setw(10) << "- Phone num : " << _list_of_contact[i - 1].get_phone_number() << "\n";
	std::cout << std::setw(10) << "- Dark sec : " << _list_of_contact[i - 1].get_darkest_secret() << "\n";
	std::cout << "\n";
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
	for (size_t i = 0; i < _nb_contact; i++)
		display_contact(i + 1);
}

int	PhoneBook::exit_prompt()
{
	std::string	user_line;

	if (!_nb_contact)
		return (0);
	std::cout << "Entrez un id pour voir un user" << "\n";
	while (getline(std::cin, user_line))
	{
		if (is_number(user_line)
			&& atoi(user_line.c_str()) <= (int)_nb_contact
			&& atoi(user_line.c_str()) > 0)
		{
			display_contact_full(atoi(user_line.c_str()));
			return (0);	
		}
		else
			std::cout << "Wrong id\n";
	}
	return (1);
}

int		PhoneBook::search_contact()
{
	display_contacts();
	if (exit_prompt())
		return (1);
	return (0);
}
