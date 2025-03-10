/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:16:40 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/04 01:28:35 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors and destructor
MateriaSource::MateriaSource()
{
	DEBUG_LOG("MateriaSource default constructor", BLUE);
	for (int i = 0; i < MAX_MATERIA; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	DEBUG_LOG("MateriaSource copy constructor", BLUE);
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (src.materia[i])
			this->materia[i] = src.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	DEBUG_LOG("MateriaSource destructor", BLUE);
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->materia[i])
			delete this->materia[i];
	}
}

// Operator overloads
MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	DEBUG_LOG("MateriaSource assignment operator", BLUE);
	if (this == &src)
		return (*this);

	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->materia[i])
			delete this->materia[i];
		if (src.materia[i])
			this->materia[i] = src.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
	return (*this);
}

// Methods
void MateriaSource::learnMateria(AMateria *m)
{
	DEBUG_LOG("MateriaSource learnMateria", GREEN);
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->materia[i] == NULL)
		{
			this->materia[i] = m;
			return;
		}
	}
	std::cout << "MateriaSource is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	DEBUG_LOG("MateriaSource createMateria", YELLOW);
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->materia[i] && this->materia[i]->getType() == type)
			return (this->materia[i]->clone());
	}
	return (NULL);
}
