#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

#include <cstdlib>
#include <ctime>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main()

{
	srand(time(NULL));
	std::cout << "=== Testing Base Type Identification ===" << std::endl;
	
	for (int i = 0; i < 5; i++)

{
		std::cout << "\n--- Test " << i + 1 << " ---" << std::endl;
		
		Base* ptr = generate();
		if (!ptr)

{
			std::cout << "Generation failed" << std::endl;
			continue;
		}
		std::cout << "Identify by pointer: ";
		identify(ptr);
		std::cout << "Identify by reference: ";
		identify(*ptr);
		
		delete ptr;
	}
	
	std::cout << "\n=== Testing with manually created objects ===" << std::endl;

	A a;
	B b;
	C c;
	
	std::cout << "\nTesting A:" << std::endl;
	std::cout << "By pointer: ";
	identify(&a);
	std::cout << "By reference: ";
	identify(a);
	
	std::cout << "\nTesting B:" << std::endl;
	std::cout << "By pointer: ";
	identify(&b);
	std::cout << "By reference: ";
	identify(b);
	
	std::cout << "\nTesting C:" << std::endl;
	std::cout << "By pointer: ";
	identify(&c);
	std::cout << "By reference: ";
	identify(c);
	
	return 0;
}
