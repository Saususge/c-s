#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = newZombie("HeapWalker");
    heapZombie->announce();
    randomChump("StackZombie");    
    Zombie* anotherHeapZombie = newZombie("PersistentZombie");
    anotherHeapZombie->announce();
    Zombie stackZombie("LocalZombie");
    stackZombie.announce();
    delete heapZombie;
    delete anotherHeapZombie;
    return 0;
}
