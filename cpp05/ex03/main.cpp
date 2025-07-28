#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    Form* rrf;

    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat b("Hermes", 1);
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        rrf = someRandomIntern.makeForm("non-existent form", "Bender");
        delete rrf;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
