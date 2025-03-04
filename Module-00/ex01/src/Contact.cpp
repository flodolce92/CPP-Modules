/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:33:06 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/26 16:20:47 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

Contact::~Contact()
{}

// Read contact field and check if it's empty
static	std::string readField(std::string field)
{
	std::string	input;

	while (true)
	{
		std::cout << "Enter the " << field << ": ";
		std::getline(std::cin, input);
		if (!input.empty() && input.find_first_not_of(' ') != std::string::npos)
			break ;
		std::cout << "The " << field << " cannot be empty or only spaces." << std::endl;
	}
	return (input);
}

// Create contact
void	Contact::createContact()
{
	this->firstName = readField("first name");
	this->lastName = readField("last name");
	this->nickname = readField("nickname");
	this->phoneNumber = readField("phone number");
	this->darkestSecret = readField("darkest secret");

	std::cout << "Contact created successfully!" << std::endl;
}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}

std::string Contact::getLastName() const
{
	return (this->lastName);
}

std::string Contact::getNickname() const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}
