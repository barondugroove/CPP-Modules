/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:57:34 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/07 17:25:58 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>

class Form {
    public :
		Form();
		Form(std::string name);
		Form(std::string name, unsigned int _sign, unsigned int _exec);
		Form(unsigned int _sign, unsigned int _exec);
		Form(Form const &src);
		~Form();

		Form &operator=(Form const &rhs);

		class GradeTooHighException : std::exception {
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : std::exception {
			public :
				virtual const char* what() const throw();
		};
		
		class FormAlreadySigned : std::exception {
			public :
				virtual const char* what() const throw();
		};

		std::string const	getName(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecGrade(void) const;
		bool				isSigned(void) const;
		void				beSigned(Bureaucrat const &signee);
		void				checkSigning(unsigned int grade) const;
		void				checkGrade(unsigned int grade) const;
		

    private :
        std::string const   _name;
        bool				_signed;
        unsigned int const	_signGrade;
		unsigned int const	_execGrade;
};

std::ostream & operator<<(std::ostream &o, Form const &src);

#endif