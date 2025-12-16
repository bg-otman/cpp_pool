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

bool is_pseudo_literals(const std::string& s)
{
    return (s == "nan" || s == "nanf"
        || s == "+inf" || s == "-inf"
        || s == "+inff" || s == "-inff");
}

void ScalarConverter::convert(const std::string& str)
{
    Type type = DetectType::detect_type(str);
    if (type == NONE)
    {
        std::cerr << "Invalid Type, ONLY : CHAR, INT, FLOAT and DOUBLE ALLOWED"  << std::endl;
        std::cerr << "NOTE FOR CHAR IT MUST BE WITH THIS FORMAT : ex: ./convert \"\'a'\""  << std::endl;
        return ;
    }

    double check_val;
    if (type == CHAR)
        check_val = static_cast<double>(str[1]);
    else
        check_val = std::strtod(str.c_str(), NULL);

    bool is_pseudo = is_pseudo_literals(str);
    std::cout << std::fixed << std::setprecision(1);
    
    // char
    std::cout << "char: ";
    if (check_val < 0 || check_val > 127 || is_pseudo)
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<int>(check_val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(check_val) << "'" << std::endl;
    
    // int
    std::cout << "int: ";
    if (check_val < INT_MIN || check_val > INT_MAX
        || is_pseudo)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(check_val) << std::endl;
    
    // float
    std::cout << "float: ";
    if ((check_val < -FLT_MAX || check_val > FLT_MAX) && !is_pseudo)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<float>(check_val) << "f" << std::endl;
    
    // double
    std::cout << "double: ";
    if ((check_val < -DBL_MAX || check_val > DBL_MAX) && !is_pseudo)
        std::cout << "impossible" << std::endl;
    else
        std::cout << check_val << std::endl;
}


