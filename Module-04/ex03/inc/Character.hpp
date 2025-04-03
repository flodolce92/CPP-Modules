/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:49:11 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/03 21:19:03 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include "debug.hpp"
#include "ICharacter.hpp"

#define MAX_INVENTORY 4

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[MAX_INVENTORY];
	
	public:
		// Constructors and destructor
		Character();
		Character(std::string name);
		Character(Character const &src);
		~Character();
	
		// Operator overloads
		Character &operator=(Character const &src);
	
		// Methods
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		bool isInventoryFull() const;
	
		// Getters
		std::string const &getName() const;
		AMateria *getInventoryItem(int idx) const;
};

#endif
