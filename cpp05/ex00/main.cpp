#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b1("Bender", 0);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Fry", 151);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Leela", 1);
        std::cout << b3 << std::endl;
        b3.incrementGrade();
        std::cout << b3 << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Zoidberg", 150);
        std::cout << b4 << std::endl;
        b4.decrementGrade();
        std::cout << b4 << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Professor", 42);
        std::cout << b5 << std::endl;
        b5.incrementGrade();
        std::cout << b5 << std::endl;
        b5.decrementGrade();
        std::cout << b5 << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
