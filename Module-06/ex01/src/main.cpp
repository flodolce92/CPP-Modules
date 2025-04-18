/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:37:19 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/18 22:34:35 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void loadCharacter(Data *character)
{
	character->name = "Salazar";
	character->race = "Vishkanya";
	character->_class = "Bard";
	character->level = 8;
}

void displayData(const Data *character)
{
	std::cout << "Name:\t" << character->name << std::endl;
	std::cout << "Race:\t" << character->race << std::endl;
	std::cout << "Class:\t" << character->_class << std::endl;
	std::cout << "Level:\t" << character->level << std::endl;
}

bool compareData(const Data *a, const Data *b)
{
	return (a->name == b->name &&
			a->race == b->race &&
			a->_class == b->_class &&
			a->level == b->level);
}

int main()
{
	Data character;
	loadCharacter(&character);

	Data *original_ptr = &character;
	std::cout << std::hex;

	std::cout << "Original character address:\t" << original_ptr << std::endl;
	displayData(original_ptr);

	// Serialize
	uintptr_t serialized_ptr = Serializer::serialize(original_ptr);
	std::cout << "\n[Serialization]" << std::endl;
	std::cout << "Serialized uintptr_t:\t" << serialized_ptr << std::endl;

	// Deserialize
	Data *deserialized_ptr = Serializer::deserialize(serialized_ptr);
	std::cout << "\n[Deserialization]" << std::endl;
	std::cout << "Deserialized character address:\t" << deserialized_ptr << std::endl;
	displayData(deserialized_ptr);

	// Verifications
	std::cout << "\n[Verification]" << std::endl;
	std::cout << "Pointers match:\t" << ((original_ptr == deserialized_ptr) ? "true" : "false") << std::endl;
	std::cout << "Data matches:\t" << (compareData(original_ptr, deserialized_ptr) ? "true" : "false") << std::endl;

	return (0);
}
