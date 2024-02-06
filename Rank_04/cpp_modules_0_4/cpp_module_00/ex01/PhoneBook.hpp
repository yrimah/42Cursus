#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];

        int contactIndex(void) const;

    public:
        PhoneBook();
        ~PhoneBook();

        void setupPhonebook(void) const;
        void add(void);
        void search(void) const;
        void showContacts(void) const;
        // Contact();
        // void EXIT();
};

#endif // PHONEBOOK_HPP