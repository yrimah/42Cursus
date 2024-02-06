#include "File.hpp"

File::File()
{
}

File::~File()
{
}

void File::setFilename(std::string fileName)
{
    this->fileName = fileName;
}
void File::setS1(std::string s1)
{
    this->s1 = s1;
}
void File::setS2(std::string s2)
{
    this->s2 = s2;
}

std::string File::getFilename(void) const
{
    return (this->fileName);
}
std::string File::getS1(void) const
{
    return (this->s1);
}
std::string File::getS2(void) const
{
    return (this->s2);
}