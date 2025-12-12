/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:56:58 by njooris           #+#    #+#             */
/*   Updated: 2025/12/12 14:46:17 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_H
# define PhoneBook_H
#include <string>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	_list_of_contact[8];
		size_t	_index_contact;
		size_t	_nb_contact;
	public:
		PhoneBook();
		void	add_contact(Contact contact);
		int		build_contact();
		void	search_contact();	
		void	display_contacts();
		void	display_contact(int i);
		void	exit_prompt();
		void	display_contact_full(int i);

};

#endif