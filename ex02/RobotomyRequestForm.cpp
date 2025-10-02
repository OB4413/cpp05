#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("unknown"){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other){
	target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target){}

std::string RobotomyRequestForm::getTarget() const{ return target;}

static int robot_chooses = 0;

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if(executor.getgrade() > getgrade_execute())
		throw AForm::GradeTooLowException();
	else if(getsign() == false)
		throw AForm::FormNotSignedException();
	else if(robot_chooses++ % 2 == 0)
	{
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
		std::cout << executor.getname() << " executed ShrubberyCreationForm" << std::endl;
	}
	else
		std::cout << "the robotomy failed" << std::endl;
}
