#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

struct Data
{
    int u_id;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& oSerializer);
		Serializer& operator=(const Serializer& oSerializer);
    
    public:
        ~Serializer();

		static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif