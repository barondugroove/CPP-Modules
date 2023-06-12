/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:09:55 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/12 17:23:13 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_CPP
# define SHRUBERRYCREATIONFORM_CPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public :
		ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &rhs);
        ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

        void	execute(Bureaucrat const & executor) const;

	private :
		ShrubberyCreationForm();
        std::string const   target;
};

#endif