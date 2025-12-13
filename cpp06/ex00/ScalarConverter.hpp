#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cfloat>

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

bool is_pseudo_literals(const std::string& s);

#endif
