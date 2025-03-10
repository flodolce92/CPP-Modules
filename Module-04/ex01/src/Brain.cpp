/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:26:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/01 00:17:17 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Private methods
void Brain::initIdeas()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "<none>";
}

// Constructors and destructor
Brain::Brain()
{
	DEBUG_LOG("Brain default constructor");

	this->initIdeas();
}

Brain::Brain(const Brain &src)
{
	DEBUG_LOG("Brain copy constructor");

	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

Brain::~Brain()
{
	DEBUG_LOG("Brain destructor");
}

// Operator overloads
Brain &Brain::operator=(const Brain &src)
{
	DEBUG_LOG("Brain assignation operator");

	if (this == &src)
		return (*this);

	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

// Getters
std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (this->ideas[index]);
}

// Setters
void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
		return ;
	this->ideas[index] = idea;
}
