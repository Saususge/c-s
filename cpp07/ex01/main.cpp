
#include "iter.hpp"

template <typename T>
void print(T &i)

{
    std::cout << i << std::endl;
}

int main()

{
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print);
    return 0;
}
