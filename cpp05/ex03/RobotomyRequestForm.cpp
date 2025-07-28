#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("Robotomy Request", 72, 45, target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : Form(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    Form::operator=(other);
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy of " << getTarget() << " failed" << std::endl;
}
