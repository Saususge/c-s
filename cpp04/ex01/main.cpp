#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
    
    const int arraySize = 4;
    Animal* animals[arraySize];
    
    for (int idx = 0; idx < arraySize; idx++)
    {
        if (idx < arraySize / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }
    
    for (int idx = 0; idx < arraySize; idx++)
    {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }
    for (int idx = 0; idx < arraySize; idx++)
        delete animals[idx];
    
    Dog originalDog;

    originalDog.getBrain()->setIdea(0, "I love bones");
    originalDog.getBrain()->setIdea(1, "Chase the cat");
    
    Dog copiedDog(originalDog);

    originalDog.getBrain()->setIdea(0, "I love food");
    
    std::cout << "Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog idea 1: " << copiedDog.getBrain()->getIdea(1) << std::endl;
    
    Dog assignedDog;

    assignedDog = originalDog;
    originalDog.getBrain()->setIdea(0, "I love treats");
    std::cout << "Original dog idea 0 after assignment: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned dog idea 0: " << assignedDog.getBrain()->getIdea(0) << std::endl;
    
    Cat originalCat;

    originalCat.getBrain()->setIdea(0, "I love fish");
    
    Cat copiedCat(originalCat);

    originalCat.getBrain()->setIdea(0, "I love milk");
    std::cout << "Original cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied cat idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    
    return 0;
}
