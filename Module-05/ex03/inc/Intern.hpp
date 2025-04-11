/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:45:07 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 21:33:32 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "debug.hpp"
# include "AForm.hpp"

class Intern
{
	private:
		struct FormMap
		{
			const char *name;
			AForm *(*create)(const std::string &target);
		};

		// Private Methods
		static AForm *createShrubbery(const std::string &target);
		static AForm *createRobotomy(const std::string &target);
		static AForm *createPresidential(const std::string &target);

	public:
		// Constructors and destructor
		Intern();
		Intern(const Intern &src);
		~Intern();

		// Operator overloads
		Intern &operator=(const Intern &src);

		// Methods
		AForm *makeForm(const std::string &nameForm, const std::string &target);
};

#endif
