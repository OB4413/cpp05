#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool sign;
		const int grade_sign;
		const int grade_execute;
	public:
		//ocf
		AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		AForm(std::string name , int gr_sign, int gr_execute);
		class GradeTooLowException: public std::exception
		{
			const char* what() const _GLIBCXX_NOTHROW;
		};
		class GradeTooHighException: public std::exception
		{
			const char* what() const _GLIBCXX_NOTHROW;
		};
		class FormNotSignedException: public std::exception
		{
			const char* what() const _GLIBCXX_NOTHROW;
		};
		std::string getname();
		bool getsign() const;
		int getgrade_sign();
		int getgrade_execute() const;
		void	beSigned(Bureaucrat& other);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm& other);
