#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    Bureaucrat b1("Bender", 1);
    Bureaucrat b2("Fry", 42);
    Bureaucrat b3("Leela", 150);

    ShrubberyCreationForm f1("home");
    RobotomyRequestForm f2("Bender");
    PresidentialPardonForm f3("Zoidberg");

    std::cout << "--- Shrubbery Creation Form ---" << std::endl;
    b1.signForm(f1);
    b1.executeForm(f1);

    std::cout << "\n--- Robotomy Request Form ---" << std::endl;
    b2.signForm(f2);
    b2.executeForm(f2);
    b1.executeForm(f2);

    std::cout << "\n--- Presidential Pardon Form ---" << std::endl;
    b3.signForm(f3);
    b1.signForm(f3);
    b1.executeForm(f3);

    return 0;
}
