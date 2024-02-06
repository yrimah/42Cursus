#ifndef FILE_HPP
# define FILE_HPP

# include <iostream>
# include <fstream>

class File
{
    private:
        std::string fileName;
        std::string s1;
        std::string s2;

    public:
        File();
        ~File();
        void setFilename(std::string fileName);
        void setS1(std::string s1);
        void setS2(std::string s2);
        std::string getFilename(void) const;
        std::string getS1(void) const;
        std::string getS2(void) const;
};

#endif
