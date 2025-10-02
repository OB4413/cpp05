#include "AForm.hpp"

AForm::AForm(): name("unknown"), grade_sign(150), grade_execute(150){
	sign = false;
}

AForm::AForm(const AForm& other)
: name(other.name), grade_sign(other.grade_sign), grade_execute(other.grade_execute){
	sign = false;
}

AForm& AForm::operator=(const AForm& other){
	(void)other;
	return *this;
}

AForm::~AForm(){}

AForm::AForm(std::string name, int gr_sign, int gr_execute)
: name(name), grade_sign(gr_sign), grade_execute(gr_execute){
	sign = false;
	if (gr_sign > 150 || gr_execute > 150)
		throw AForm::GradeTooLowException();
	else if (gr_sign < 1 || gr_execute < 1)
		throw AForm::GradeTooHighException();
}

const char* AForm::GradeTooLowException::what() const _GLIBCXX_NOTHROW{
	return "Grade Too Low";
}

const char* AForm::GradeTooHighException::what() const _GLIBCXX_NOTHROW{
	return "Grade Too High";
}

const char* AForm::FormNotSignedException::what() const _GLIBCXX_NOTHROW{
	return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, AForm& other){
	os << "AForm " << other.getname() << " has grade sign " << other.getgrade_sign() << " and " << other.getgrade_execute()<< ", the for is " << other.getsign() << " (1, true)/(0, false) ";
	return os;
}

std::string AForm::getname(){
	return name;
}
bool AForm::getsign() const{
	return sign;
}

int AForm::getgrade_sign(){
	return grade_sign;
}
int AForm::getgrade_execute() const{
	return grade_execute;
}

void	AForm::beSigned(Bureaucrat& other){
	if (other.getgrade() <= this->grade_sign)
		sign = true;
	else
		throw AForm::GradeTooLowException();
}


