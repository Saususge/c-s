#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form("Shrubbery Creation", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : Form(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    Form::operator=(other);
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream file((getTarget() + "_shrubbery").c_str());
    file << "      /\\" << std::endl;
    file << "     /\\*\\" << std::endl;
    file << "    /\\*\\*\\" << std::endl;
    file << "   /\\*\\*\\*\\" << std::endl;
    file << "  /\\*\\*\\*\\*\\" << std::endl;
    file << "      ||" << std::endl;
    file.close();
}