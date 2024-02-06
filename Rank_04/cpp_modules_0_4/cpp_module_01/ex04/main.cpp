#include "File.hpp"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string tmp;
		std::string Content;
		std::fstream to_open;
		size_t position;
		size_t i;
		size_t j;
		size_t size;
		File *myfile = new File();

		myfile->setFilename(argv[1]);
		myfile->setS1(argv[2]);
		myfile->setS2(argv[3]);
	    
		to_open.open(myfile->getFilename(), std::ios::in);
		if (!to_open.is_open())
		{
			std::cerr << "Can't open file: " << myfile->getFilename() << std::endl;
			delete (myfile);
			exit(1);
		}
		while (std::getline(to_open, tmp))
		{
			position = tmp.find(myfile->getS1());
			while (position != std::string::npos)
			{
				i = position;
				j = 0;
				size = (myfile->getS1()).size();
				while (size--)
				{
					tmp[i] = (myfile->getS2())[j];
					i++;
					j++;
				}
				position = tmp.find(myfile->getS1());
			}
			Content += tmp + "\n";
		}
		to_open.close();
		to_open.open(myfile->getFilename(), std::ios::out);
		if (!to_open.is_open())
		{
			std::cerr << "Can't open file" << myfile->getFilename() << std::endl;
			delete (myfile);
			exit(1);
		}
		if (!Content.empty())
			to_open << Content;
		if (to_open.fail())
		{
			std::cerr << "Error in the input/output operations !" << std::endl;
			exit(1);
		}
		to_open.close();
		delete (myfile);
		return (0);
	}
	else
		std::cout << "Invalid number of argument" << std::endl;
    return (1);
}
