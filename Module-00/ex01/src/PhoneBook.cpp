/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:09:47 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/26 16:21:28 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contactsCount = 0;
}

PhoneBook::~PhoneBook()
{}

// Add contact
void	PhoneBook::addContact()
{
	if (this->contactsCount == 8)
	{
		std::cout << "The phone book is full." << std::endl;
		std::cout << "I'm replacing the oldest contact." << std::endl;
		for (int i = 0; i < 7; i++)
		{
			this->contacts[i] = this->contacts[i + 1];
		}
		this->contactsCount--;
	}
	this->contacts[this->contactsCount].createContact();
	this->contactsCount++;
}

// Truncate string
static	std::string trunc(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

// Display contacts
void	PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->contactsCount; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << trunc(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << trunc(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << trunc(this->contacts[i].getNickname()) << std::endl;
	}
}

// Display contact by index
void	PhoneBook::displayContact(int index) const
{
	std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

// Get contacts count
int	PhoneBook::getContactsCount() const
{
	return (this->contactsCount);
}
