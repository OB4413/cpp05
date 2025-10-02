#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("unknown"), grade(150){
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name){
	grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int gr): name(name){
	if (gr > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (gr < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = gr;
}

const char* Bureaucrat::GradeTooLowException::what() const _GLIBCXX_NOTHROW{
	return "Grade Too Low";
}

const char* Bureaucrat::GradeTooHighException::what() const _GLIBCXX_NOTHROW{
	return "Grade Too High";
}

std::string Bureaucrat::getname(){ return name;}

int Bureaucrat::getgrade(){ return grade;}

void Bureaucrat::increment_grade(){
	if (grade > 1)
		grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement_grade(){
	if (grade < 150)
		grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& other){
	os << other.getname() << " , bureaucrat grade " << other.getgrade();
	return os;
}
