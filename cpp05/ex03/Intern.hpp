#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"

class Intern {
public:
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

    Form* makeForm(const std::string& formName, const std::string& target);

    class FormNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
