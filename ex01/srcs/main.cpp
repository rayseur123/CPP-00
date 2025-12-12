/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:25:59 by njooris           #+#    #+#             */
/*   Updated: 2025/12/12 14:40:27 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	std::string user_line;
	PhoneBook	PhoneBook;
	
	std::cout << "Entrez une commande\n";
	while (getline(std::cin, user_line))
	{
		if (user_line == "ADD")
		{
			if (PhoneBook.build_contact())
				return (1);
		}
		if (user_line == "SEARCH")
			PhoneBook.search_contact();
		if (user_line == "EXIT")
			return (0);
		std::cout << "Entrez une commande\n";
	}
	return (0);
}