#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<class T>
class Array
{
    private:
        T *new_array;
        unsigned int array_size;

    public:
        Array()
        {
            // std::cout << "Default constructer called." std::endl;
            array_size = 0;
            new_array = new T();
        }
        Array(unsigned int n)
        {
            // std::cout << "Parametrized constructer called." std::endl;
            this->array_size = n;
            this->new_array = new T[array_size];
        }
        Array(Array const &oArray)
        {
            this->array_size = oArray.array_size;
            this->new_array = new T[this->array_size];
            for (unsigned int i = 0; i < this->array_size; i++)
                this->new_array[i] = oArray.new_array[i];
        }
        Array &operator=(Array const &oArray)
        {
            if (this != &oArray)
            {
                delete [] new_array;
                this->new_array = new T[oArray.size()];
                this->array_size = oArray.array_size;
                for (unsigned int i = 0; i < oArray.array_size; i++)
                    this->new_array[i] = oArray.new_array[i];
            }
            return (*this);
        }
        unsigned int size() const
        {
            return (array_size);
        }
        ~Array()
        {
            delete [] new_array;
        }
        T &operator[](unsigned int index) const
        {
            if (index >= array_size || index < 0)
                throw OutOfBoundException();
            return (this->new_array[index]);
        }
        class OutOfBoundException : public std::exception
        {
            public:
                virtual const char * what () const throw ()
                {
                    return ("Index out of range !!!");
                }
        };
};

template<typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &oArray)
{
    for (unsigned int i = 0; i < oArray.size(); i++)
        o << "Element " << i << " = " << oArray[i] << std::endl;
    return (o);
}

#endif
