/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 16:46:45 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/23 20:27:29 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define DEBUG 1

# include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(std::string name = "Bureaucrat101", int grade = 150);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);
		Bureaucrat			&operator=(Bureaucrat const &copy);

		Bureaucrat			&operator+=(int i);
		Bureaucrat			&operator-=(int i);
		std::string const	&getName(void) const;
		int					getGrade(void) const;
		void				setGrade(int grade);

		class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException(void) throw();
			GradeTooHighException(GradeTooHighException const &copy) throw();
			virtual ~GradeTooHighException(void) throw();
			GradeTooHighException	&operator=(GradeTooHighException const &copy) throw();
			virtual const char		*what(void) const throw();
	};

		class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException(void) throw();
			GradeTooLowException(GradeTooLowException const &copy) throw();
			virtual ~GradeTooLowException(void) throw();
			GradeTooLowException	&operator=(GradeTooLowException const &copy) throw();
			virtual const char		*what(void) const throw();
	};
};

std::ostream			&operator<<(std::ostream &o, Bureaucrat const &copy);

#endif
