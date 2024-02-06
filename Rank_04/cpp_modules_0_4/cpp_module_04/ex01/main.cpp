#include "Cat.hpp"
#include "Dog.hpp"
// #include "WrongCat.hpp"

int main()
{
    {   
        Animal *oAnimal[6];

        oAnimal[0] = new Dog();
        oAnimal[1] = new Cat();
        oAnimal[2] = new Dog();
        oAnimal[3] = new Cat();
        oAnimal[4] = new Dog();
        oAnimal[5] = new Cat();

        for (int i = 0; i < 6; i++)
            delete oAnimal[i];

        return 0;
    }
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j;
        delete i;

        return 0;
    }
}