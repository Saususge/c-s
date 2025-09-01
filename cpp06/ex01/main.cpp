#include <iostream>

#include "Serializer.hpp"

int main()

{
  Data *data = new Data;
  data->s1 = "Hello";
  data->n = 42;
  data->s2 = "World";

  size_t raw = Serializer::serialize(data);
  Data *deserialized_data = Serializer::deserialize(raw);

  std::cout << "Original pointer: " << data << std::endl;
  std::cout << "Deserialized pointer: " << deserialized_data << std::endl;

  std::cout << "Original data: " << data->s1 << ", " << data->n << ", "
            << data->s2 << std::endl;
  std::cout << "Deserialized data: " << deserialized_data->s1 << ", "
            << deserialized_data->n << ", " << deserialized_data->s2
            << std::endl;

  if (data == deserialized_data)
    std::cout << "Pointers are equal." << std::endl;
  else
    std::cout << "Pointers are not equal." << std::endl;

  delete data;

  return 0;
}
