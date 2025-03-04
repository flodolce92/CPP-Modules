/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:38:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/26 16:22:17 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void searchContacts(PhoneBook &phoneBook)
{
	int	index;

	phoneBook.displayContacts();
	if (phoneBook.getContactsCount() == 0)
		return ;
	std::cout << "Enter the index of the contact you want to see: ";
	if (std::cin >> index)
	{
		std::cin.ignore();
		index -= 1;
		if (index >= 0 && index < phoneBook.getContactsCount())
			phoneBook.displayContact(index);
		else
			std::cout << "Invalid index." << std::endl;
	}
	else
	{
		std::cout << "Invalid input. Please enter a number." << std::endl;
		std::cin.clear();
		std::cin.ignore(10, '\n');
	}
}

int	main()
{
	PhoneBook	phoneBook;

	while (true)
	{
		std::string command;

		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			searchContacts(phoneBook);
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}
