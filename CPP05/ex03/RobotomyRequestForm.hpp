/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:09:55 by bchabot           #+#    #+#             */
/*   Updated: 2023/06/08 18:09:40 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_CPP
# define ROBOTOMYREQUESTFORM_CPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public :
		RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &rhs);
        RobotomyRequestForm(AForm const &src);
        ~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

        void	execute(Bureaucrat const & executor) const;

	private :
		RobotomyRequestForm();
        std::string const   target;
};

#endif