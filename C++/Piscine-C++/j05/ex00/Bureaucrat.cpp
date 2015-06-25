/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 20:25:15 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/23 20:27:53 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(150)
{
	this->setGrade(grade);
	if (DEBUG) std::cout << "Constructed " << *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	if (DEBUG) std::cout << "Copy-constructed " << *this;
	*this = copy;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw()
{
	if (DEBUG) std::cout << "GradeTooHighException constructed." << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &copy) throw()
{
	if (DEBUG) std::cout << "GradeTooHighException copy-constructed." << std::endl;
	*this = copy;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw()
{
	if (DEBUG) std::cout << "GradeTooLowException constructed." << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &copy) throw()
{
	if (DEBUG) std::cout << "GradeTooLowException copy-constructed." << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG) std::cout<< "Destructed " << *this;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
	if (DEBUG) std::cout << "GradeTooHighException destructed." << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	if (DEBUG) std::cout << "GradeTooLowException destructed." << std::endl;
}

Bureaucrat				&Bureaucrat::operator=(Bureaucrat const &copy)
{
	this->setGrade(copy._grade);

	return *this;
}

Bureaucrat				&Bureaucrat::operator+=(int i)
{
	this->setGrade(this->_grade - i);

	return *this;
}

Bureaucrat				&Bureaucrat::operator-=(int i)
{
	this->setGrade(this->_grade + i);

	return *this;
}

Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &copy) throw()
{
	static_cast<void>(copy);

	return *this;
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &copy) throw()
{
	static_cast<void>(copy);

	return *this;
}

std::ostream			&operator<<(std::ostream &o, Bureaucrat const &copy)
{
	o << copy.getName( ) << ", bureaucrat grade "
		<< copy.getGrade( ) << std::endl;

	return o;
}

const char				*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "GradeTooHighException";
}

const char				*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "GradeTooLowException";
}

void				Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();

	this->_grade = grade;
}

std::string const	&Bureaucrat::getName(void) const { return this->_name; }
int					Bureaucrat::getGrade(void) const { return this->_grade; }
