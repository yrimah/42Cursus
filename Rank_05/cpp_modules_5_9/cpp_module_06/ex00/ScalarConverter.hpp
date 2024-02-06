#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& oScalarConverter);
		ScalarConverter& operator=(const ScalarConverter& oScalarConverter);
    
    public:
        ~ScalarConverter();

		static void convert(const std::string& literal);

};

#endif