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
    double check_val = std::atof(str.c_str());
    
    // convert to actual type
    switch (type)
    {
        case CHAR:
            char_type = str[1];
            break;
        case INT:
            int_type = atoi(str.c_str());
            break;
        case FLOAT:
            float_type = std::atof(str.c_str());
            break;
        case DOUBLE:
            double_type = std::atof(str.c_str());
            break;
        default:
            break;
    }
    // casting to other types
    switch (type)
    {
        case CHAR:
            int_type = static_cast<int>(char_type);
            float_type = static_cast<float>(char_type);
            double_type = static_cast<double>(char_type);
            break;
        case INT:
            char_type = static_cast<char>(int_type);
            float_type = static_cast<float>(int_type);
            double_type = static_cast<double>(int_type);
            break;
        case FLOAT:
            char_type = static_cast<char>(float_type);
            int_type = static_cast<int>(float_type);
            double_type = static_cast<double>(float_type);
            break;
        case DOUBLE:
            char_type = static_cast<char>(double_type);
            int_type = static_cast<int>(double_type);
            float_type = static_cast<float>(double_type);
            break;
        default:
            break;
    }

}

void fromChar(char c, int i, float f, double d)
{
    // char
    isprint(c) ? std::cout << c : std::cout << "Non displayable";
    std::cout << std::endl;
    // int
    std::cout << i << std::endl;
    // float
    std::cout << f << std::endl;
    // double
    std::cout << d << std::endl;
}

void fromInt(double check, std::string s, char c, int i, float f, double d)
{
    // char
    std::cout << "char: ";
    if (check < 0 || check > 127)
        std::cout << "impossible" << std::endl;
    else if (!isprint(i))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << c << std::endl;
    
    // int
    std::cout << "int: ";
    if (check < INT_MIN || check > INT_MAX
        || s == "nan" || s == "nanf"
        || s == "+inf" || s == "-inf")
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;
    
    // float
    std::cout << "float: ";
    if (check < FLOAT_MIN || check > FLOAT_MAX)
        std::cout << "impossible" << std::endl;
    else if (s == "nan" || s == "nanf")
        std::cout << "nanf" << std::endl;
    else if (s == "+inf" || s == "+inff")
        std::cout << "+inff" << std::endl;
    else if (s == "-inf" || s == "-inff")
        std::cout << "-inff" << std::endl;
    else
        std::cout << f << std::endl;
    
    // double
    std::cout << "double: ";
    if (check < DOUBLE || check > DOUBLE_MAX)
        std::cout << "impossible" << std::endl;
    else if (s == "nan" || s == "nanf")
        std::cout << "nan" << std::endl;
    else if (s == "+inf" || s == "+inff")
        std::cout << "+inf" << std::endl;
    else if (s == "-inf" || s == "-inff")
        std::cout << "-inf" << std::endl;
    else
        std::cout << d << std::endl;
}
