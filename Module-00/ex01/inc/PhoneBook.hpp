/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:08:21 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/25 23:27:38 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int contactsCount;

	public:
		PhoneBook();
		~PhoneBook();

		// Add contact
		void addContact();

		// Display contacts
		void displayContacts() const;

		// Display contact by index
		void displayContact(int index) const;

		// Get contacts count
		int getContactsCount() const;
};

#endif
