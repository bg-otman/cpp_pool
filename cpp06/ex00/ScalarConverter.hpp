#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

enum Type
{
    NONE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter &operator=(const ScalarConverter& obj);
        ~ScalarConverter();
    public:
        static void convert(const std::string& str);
};

#endif
