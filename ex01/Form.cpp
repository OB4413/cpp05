#include "Form.hpp"

Form::Form(): name("unknown"), grade_sign(150), grade_execute(150){
	sign = false;
}

Form::Form(const Form& other)
: name(other.name), grade_sign(other.grade_sign), grade_execute(other.grade_execute){
	sign = false;
}

Form& Form::operator=(const Form& other){
	(void)other;
	return *this;
}

Form::~Form(){}

Form::Form(std::string name, int gr_sign, int gr_execute)
: name(name), grade_sign(gr_sign), grade_execute(gr_execute){
	sign = false;
	if (gr_sign > 150 || gr_execute > 150)
		throw Form::GradeTooLowException();
	else if (gr_sign < 1 || gr_execute < 1)
		throw Form::GradeTooHighException();
}

const char* Form::GradeTooLowException::what() const _GLIBCXX_NOTHROW{
	return "Grade Too Low";
}

const char* Form::GradeTooHighException::what() const _GLIBCXX_NOTHROW{
	return "Grade Too High";
}

std::ostream& operator<<(std::ostream& os, Form& other){
	os << "Form " << other.getname() << " has grade sign " << other.getgrade_sign() << " and " << other.getgrade_execute() << ", the for is (0, true)/(1, false) " << other.getsign();
	return os;
}

std::string Form::getname(){
	return name;
}
bool Form::getsign(){
	return sign;
}

int Form::getgrade_sign(){
	return grade_sign;
}
int Form::getgrade_execute(){
	return grade_execute;
}

void	Form::beSigned(Bureaucrat& other){
	if (other.getgrade() <= this->grade_sign)
		sign = true;
	else
		throw Form::GradeTooLowException();
}


