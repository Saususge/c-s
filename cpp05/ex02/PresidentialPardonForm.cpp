#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Form("Presidential Pardon", 25, 5, target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : Form(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    Form::operator=(other);
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
