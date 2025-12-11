#include "ScalarConverter.hpp"
#include "DetectType.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    (void) obj;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void) obj;
    return *this;
}


void ScalarConverter::convert(const std::string& str)
{
    Type type = DetectType::detect_type(str);
    if (type == NONE)
    {
        std::cout << "char: impossible"  << std::endl;
        std::cout << "int: impossible"  << std::endl;
        std::cout << "float: impossible"  << std::endl;
        std::cout << "double: impossible"  << std::endl;
        return ;
    }
    char char_type;
    int int_type;
    float float_type;
    double double_type;

    switch (type)
    {
        case CHAR:
            char_type = str[1];
            break;
        case INT:
            int_type = atoi(str.c_str());
            break;
        case FLOAT:
            // float_type = ;   ///strtod
            break;
        default:
            break;
    }
}


/*

    // std::cout << "test : [" << type << "]\n";
    switch (type)
    {
        case NONE:
            std::cout << "it's type is :   NONE" << std::endl;
            break;
        case CHAR:
            std::cout << "it's type is :   CHAR" << std::endl;
            break;
        case INT:
            std::cout << "it's type is :   INT" << std::endl;
            break;
        case FLOAT:
            std::cout << "it's type is :   FLOAT" << std::endl;
            break;
        case DOUBLE:
            std::cout << "it's type is :   DOUBLE" << std::endl;
            break;
        default:
            break;
    }

*/