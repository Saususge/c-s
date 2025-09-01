#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) { (void)other; }

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer() {}

size_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<size_t>(ptr);
}

Data* Serializer::deserialize(size_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
