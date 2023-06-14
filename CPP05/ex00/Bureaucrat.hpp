/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:56:19 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/13 15:37:42 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>

class Bureaucrat {
	public :
		Bureaucrat(void);
		Bureaucrat(unsigned int grade);
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &rhs);
		~Bureaucrat(void);

		Bureaucrat& operator=(Bureaucrat const &src);

		const std::string 	getName(void) const;
		unsigned int		getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				check_grade(int grade) const; 

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
