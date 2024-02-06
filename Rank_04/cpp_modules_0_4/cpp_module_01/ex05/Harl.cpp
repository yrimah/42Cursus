#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "\"DEBUG\" : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "\"INFO\" : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "\"WARNING\" : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "\"ERROR\" : This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    int counter;

    counter = 0;
    void (Harl::*functions[]) (void) = {&Harl::debug, &Harl::info, &Harl::warning,&Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (counter < MAX_LEVEL && level != levels[counter])
        counter++;
    // MIN_LEVEL = counter;

    if (counter < MAX_LEVEL)
        (this->*functions[counter])();
}
