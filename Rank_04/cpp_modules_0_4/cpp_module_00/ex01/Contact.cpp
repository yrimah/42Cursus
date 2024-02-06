#include "Contact.hpp"

Contact::Contact()
{
};

Contact::~Contact()
{
};

std::string Contact::check_cmd(std::string str)
{
    std::string cmd;
    int         pass;

    pass = 0;
    while (!pass)
    {
        std::cout << str << std::flush;
        std::getline(std::cin, cmd);
        // std::cin.ignore();
        if (cmd.empty())
            std::cout << "🛑Fill the field !🛑" << std::endl;
        else
            pass = 1;
    }
    return (cmd);
}

// std::string Contact::get_fname(void) const
// {
//     return (this->d_secret);
// }

void Contact::ft_fill_fields(void)
{
    std::cin.ignore();
    first_name = check_cmd("ENTER YOUR FIRST NAME: ");
    last_name = check_cmd("ENTER YOUR LAST NAME: ");
    nickname = check_cmd("ENTER YOUR NICKNAME: ");
    phone_nbr = check_cmd("ENTER YOUR PHONE NUMBER: ");
    d_secret = check_cmd("ENTER YOUR DARKEST SECRET: ");
}

std::string Contact::tenCondition(std::string str) const
{
    if (str.length() > MAX_LEN)
        return str.substr(0, 9) + ".";
    return (str);
}

void    Contact::setIndex(int index)
{
    this->index = index;
}

int Contact::ft_isValid(void) const
{
    if (first_name.empty() || last_name.empty()
        || nickname.empty())
        return (1);
    return (0);
}

// void Contact::formFields(std::string str[3]) const
// {
//     int counter;

//     counter = 0;
//     while (counter < 3)
//         std::cout << "|" << std::setw(MAX_LEN) << this->tenCondition(str[counter++]) << std::flush;
//     std::cout << "|" << std::endl;
// }

void    Contact::setupFields(int index) const
{
    if (this->ft_isValid())
        return ;
    std::cout << "|" << std::setw(MAX_LEN) << index << std::flush;
    std::cout << "|" << std::setw(MAX_LEN) << this->tenCondition(this->first_name) << std::flush;
    std::cout << "|" << std::setw(MAX_LEN) << this->tenCondition(this->last_name) << std::flush;
    std::cout << "|" << std::setw(MAX_LEN) << this->tenCondition(this->nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::printFields(int index) const
{
    if (this->ft_isValid())
        return ;
    std::cout << std::endl;
    std::cout << "   📋📋CONTACT NUMBER " << index << "📋📋" << std::endl;
    std::cout << "|\tFirst Name\t:\t" << this->first_name << std::endl;
    std::cout << "|\tLast Name\t:\t" << this->last_name << std::endl;
    std::cout << "|\tNickname\t:\t" << this->nickname << std::endl;
    std::cout << std::endl;
}