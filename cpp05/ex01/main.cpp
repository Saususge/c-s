#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b1("Bender", 42);
        Form f1("27B/6", 50, 100);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Fry", 100);
        Form f2("27B/6", 50, 100);
        std::cout << b2 << std::endl;
        std::cout << f2 << std::endl;
        b2.signForm(f2);
        std::cout << f2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
