/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:53:36 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 16:54:07 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
# define PRESIDENTIALPARDONFORM

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	public:
		// Constructors and destructor
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		// Operator overloads
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		// Methods
		void execute(const Bureaucrat &executor) const;

		// Getters
		const std::string &getTarget() const;
};

#endif
