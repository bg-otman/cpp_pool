#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <climits>
#include <iomanip>
#include <cmath>
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

void printResults(double check, char c, int i, float f, double d);

#endif
