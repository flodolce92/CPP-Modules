/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:53:53 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 16:54:19 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;

	public:
		// Constructors and destructor
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		// Operator overloads
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		// Methods
		void execute(const Bureaucrat &executor) const;

		// Getters
		const std::string &getTarget() const;
};

#endif
