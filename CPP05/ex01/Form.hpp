/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:57:34 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/12 14:50:23 by bchabot          ###   ########.fr       */
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

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		
		class FormCantSign : public std::exception {
			public:
				FormCantSign(const std::string& bureaucrat, const std::string& form, const std::string& reason) throw() : 
					_bureaucrat(bureaucrat), _form(form),  _reason(reason) {}
				~FormCantSign() throw() {}
				virtual const char* what() const throw() ;

			private:
				std::string _bureaucrat;
				std::string _form;
				std::string _reason;
		};

		const std::string	getName(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecGrade(void) const;
		bool				isSigned(void) const;
		void				beSigned(Bureaucrat const &signee);
		void				checkSigning(Bureaucrat const &signee) const;
		void				checkGrade(unsigned int grade) const;
		

    private :
        const std::string   _name;
        bool				_signed;
        unsigned int const	_signGrade;
		unsigned int const	_execGrade;
};

std::ostream & operator<<(std::ostream &o, Form const &src);

#endif