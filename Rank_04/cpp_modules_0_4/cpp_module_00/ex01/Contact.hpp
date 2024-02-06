#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

#define MAX_LEN 10

class Contact
{
    private:
            unsigned int index;
            std::string first_name;
            std::string last_name;
            std::string nickname;
            std::string phone_nbr;
            std::string d_secret;

        std::string check_cmd(std::string str);
        std::string tenCondition(std::string str) const;
        // void formFields(std::string str[3]) const;
        int ft_isValid(void) const;

    public:
            Contact();
            ~Contact();
            void setIndex(int index);
            void ft_fill_fields(void);
            void setupFields(int index) const;
            void printFields(int index) const;
            // std::string get_fname(void) const;
};

#endif // CONTACT_HPP