/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:46:47 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/04/11 00:51:18 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "debug.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		// grade: 1 (highest possible grade) to 150 (lowest possible grade)
		int					grade;

	public:
		// Constructors and destructor
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &src);
		virtual ~Bureaucrat();

		// Operator overloads
		Bureaucrat &operator=(const Bureaucrat &src);

		// Methods
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);
		void	executeForm(AForm const &form) const;

		// Getters
		const std::string	&getName() const;
		int					getGrade() const;

		// Setters
		void setGrade(int grade);

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

// Overload operator<< to print Bureaucrat objects
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
