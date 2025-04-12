/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:12:04 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/09 19:38:57 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "debug.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		// Constructors and destructor
		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form &src);
		~Form();

		// Operator overloads
		Form &operator=(const Form &src);

		// Methods
		void beSigned(const Bureaucrat &bureaucrat);

		// Getters
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		// Setters
		void setIsSigned(const bool isSigned);

		// Exception Classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

// Overload operator<< to print Form objects
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
