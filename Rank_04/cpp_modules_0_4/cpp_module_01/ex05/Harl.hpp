#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define MAX_LEVEL 4
// # define MIN_LEVEL

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif