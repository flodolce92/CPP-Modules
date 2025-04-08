/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:45:42 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 01:04:48 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;

	public:
		// Constructors and destructor
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		// Operator overloads
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		// Methods
		void execute(const Bureaucrat &executor) const;

		// Getters
		const std::string &getTarget() const;
};

#endif
