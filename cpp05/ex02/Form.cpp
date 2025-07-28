#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _target(other._target) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

const std::string& Form::getTarget() const {
    return _target;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* Form::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "Yes" : "No")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}
