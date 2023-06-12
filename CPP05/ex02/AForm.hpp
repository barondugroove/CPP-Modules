/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:57:34 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/08 14:02:07 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>

class AForm {
    public :
		AForm();
		AForm(std::string name, unsigned int _sign, unsigned int _exec);
		AForm(unsigned int _sign, unsigned int _exec);
		AForm(AForm const &src);
		virtual ~AForm();

		AForm &operator=(AForm const &rhs);

		std::string const	getName(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecGrade(void) const;
		bool				isSigned(void) const;
		void				checkSigning(Bureaucrat const &signee) const;
		void				checkExec(Bureaucrat const &signee) const;
		void				checkGrade(unsigned int grade) const;

		void				beSigned(Bureaucrat const &signee);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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

		class FormCantExec : public std::exception {
			public:
				FormCantExec(const std::string& bureaucrat, const std::string& form, const std::string& reason) throw() : 
					_bureaucrat(bureaucrat), _form(form),  _reason(reason) {}
				~FormCantExec() throw() {}
				virtual const char* what() const throw() ;

			private:
				std::string _bureaucrat;
				std::string _form;
				std::string _reason;
		};
		
    protected :
        std::string const   _name;
        bool				_signed;
        unsigned int const	_signGrade;
		unsigned int const	_execGrade;
};

std::ostream & operator<<(std::ostream &o, AForm const &src);

#endif