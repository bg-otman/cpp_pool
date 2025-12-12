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
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;
    double check_val = std::strtod(str.c_str(), NULL);
    
    // convert to actual type
    switch (type)
    {
        case CHAR:
            c = str[1];
            break;
        case INT:
            if (check_val >= INT_MIN && check_val <= INT_MAX)
                i = static_cast<int>(check_val);
            break;
        case FLOAT:
            f = std::strtof(str.c_str(), NULL);
            break;
        case DOUBLE:
            d = std::strtod(str.c_str(), NULL);
            break;
        default:
            break;
    }
    // casting to other types
    switch (type)
    {
        case CHAR:
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        case INT:
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;
        case FLOAT:
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
            break;
        case DOUBLE:
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);
            break;
        default:
            break;
    }
    std::cout << std::fixed << std::setprecision(1);
    printResults(check_val, c, i, f, d);
}

void printResults(double check, char c, int i, float f, double d)
{
    bool is_nan = std::isnan(check);
    bool is_inf = std::isinf(check);

    // char
    std::cout << "char: ";
    if (check < 0 || check > 127 || is_nan || is_inf)
        std::cout << "impossible" << std::endl;
    else if (!isprint(i))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
    
    // int
    std::cout << "int: ";
    if (check < INT_MIN || check > INT_MAX
        || is_nan || is_inf)
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;
    
    // float
    std::cout << "float: ";
    if (is_nan || is_inf)
        std::cout << check << "f" << std::endl;
    else if (check < -FLT_MAX || check > FLT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << f << "f" << std::endl;
    
    // double
    std::cout << "double: ";
    if (is_nan || is_inf)
        std::cout << check << std::endl;
    else if (check < -DBL_MAX || check > DBL_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << d << std::endl;
}

