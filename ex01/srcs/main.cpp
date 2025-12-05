/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:25:59 by njooris           #+#    #+#             */
/*   Updated: 2025/12/05 15:59:44 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "PhoneBook.h"
#include <iostream>
#include <string>

int	main()
{
	std::string user_line;
	PhoneBook	PhoneBook;
	
	std::cout << "Entrez une commande\n";
	while (getline(std::cin, user_line))
	{
		std::cout << "Entrez une commande\n";
		if (user_line == "ADD")
			PhoneBook.build_contact();
		if (user_line == "SEARCH")
			PhoneBook.search_contact();
		if (user_line == "EXIT")
			return (0);
	}
	return (0);
}