#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool sign;
		const int grade_sign;
		const int grade_execute;
	public:
		//ocf
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		Form(std::string name , int gr_sign, int gr_execute);
		class GradeTooLowException: public std::exception
		{
			const char* what() const _GLIBCXX_NOTHROW;
		};
		class GradeTooHighException: public std::exception
		{
			const char* what() const _GLIBCXX_NOTHROW;
		};
		std::string getname();
		bool getsign();
		int getgrade_sign();
		int getgrade_execute();
		void	beSigned(Bureaucrat& other);
};

std::ostream& operator<<(std::ostream& os, Form& other);
