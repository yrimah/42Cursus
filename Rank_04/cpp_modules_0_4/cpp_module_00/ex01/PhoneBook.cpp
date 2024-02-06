#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::setupPhonebook(void) const
{
    std::cout << "⬇ WELCOME TO THE PHONEBOOK:⬇"<< std::endl << "📋📋CHOICES📋📋"<< std::endl;
    std::cout << "|   ADD      |"<< std::endl << "|   SEARCH   |"<< std::endl << "|   EXIT     |"<< std::endl;
    // std::cout << "▶ Your choice: ";
}

void PhoneBook::add(void)
{
    static int counter;
    this->contacts[counter % 8].ft_fill_fields();
    this->contacts[counter % 8].setIndex(counter);
    counter++;
}

int PhoneBook::contactIndex(void) const
{
    int typed;
    int pass;

    pass = 0;
    while (!pass)
    {
        std::cout << "▶ ENTER THE CONTACT INDEX: " << std::flush;
        std::cin >> typed;
        if (std::cin.good() && (typed > -1 && typed < 8))
            pass = 1;
        else
            // std::cin.clear();
            std::cout << "🛑Index out of range ! Try again...🛑" << std::endl;
    }
    return (typed);
}

void PhoneBook::search(void) const
{
    int counter;

    counter = this->contactIndex();
    this->contacts[counter].printFields(counter);
}

void PhoneBook::showContacts(void) const
{
    int counter;

    counter = -1;
    std::cout << "⬇ PHONEBOOK:⬇" << std::endl;
    while (++counter <= 7)
        this->contacts[counter].setupFields(counter);
    std::cout << std::endl;
}
