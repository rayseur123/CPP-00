/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:25:59 by njooris           #+#    #+#             */
/*   Updated: 2025/12/05 12:54:21 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.h"
#include "phoneBook.h"
#include <iostream>
#include <string>

int	main()
{
	int			ret = 0;
	std::string user_line;
	PhoneBook	PhoneBook;
	
	while (!ret)
	{
		std::cout << "Entrez une commande\n";
		getline(std::cin, user_line);
		if (user_line == "ADD")
			PhoneBook.build_contact();
		if (user_line == "SEARCH")
			PhoneBook.search_contact();
		if (user_line == "EXIT")
			return (0);
	}
	return (0);
}