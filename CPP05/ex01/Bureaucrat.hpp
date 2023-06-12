/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:56:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/12 14:01:10 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CPP
# define BUREAUCRAT_CPP

#include <string>
#include <stdexcept>

class Form;

class Bureaucrat {
	public :
		Bureaucrat(void);
		Bureaucrat(unsigned int grade);
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &rhs);
		~Bureaucrat(void);

		Bureaucrat& operator=(Bureaucrat const &src);

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const; 
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				check_grade(int grade) const; 
		void				signForm(Form &form) const;

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		
	private :
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &src);

#endif
