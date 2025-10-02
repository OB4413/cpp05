#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		//ocf
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat(std::string name ,int gr);
		class GradeTooLowException: public std::exception
		{
			const char* what() const _GLIBCXX_NOTHROW;
		};
		class GradeTooHighException: public std::exception
		{
			const char* what() const _GLIBCXX_NOTHROW;
		};
		std::string getname();
		int getgrade();
		void increment_grade();
		void decrement_grade();
		void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& other);
