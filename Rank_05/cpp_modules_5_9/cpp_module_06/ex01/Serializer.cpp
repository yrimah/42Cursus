#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer& oSerializer)
{ 
    *this = oSerializer;
}

Serializer& Serializer::operator=(const Serializer& oSerializer)
{
    (void)oSerializer;
    return *this;
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}