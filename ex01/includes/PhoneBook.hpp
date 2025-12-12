/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:56:58 by njooris           #+#    #+#             */
/*   Updated: 2025/12/09 13:16:22 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_H
# define PhoneBook_H
#include <string>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	list_of_contact[8];
		size_t	index_contact;
		size_t	nb_contact;
	public:
		PhoneBook();
		void	add_contact(Contact contact);
		void	build_contact();
		void	search_contact();	
		void	display_contacts();
		void	display_contact(int i);
		void	exit_prompt();
		void	display_contact_full(int i);

};

#endif