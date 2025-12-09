#include "DetectType.hpp"

DetectType::DetectType()
{
}

DetectType::DetectType(const DetectType& obj)
{
    (void) obj;
}

DetectType& DetectType::operator=(const DetectType& obj)
{
    (void) obj;
    return *this;
}

DetectType::~DetectType()
{
}

/*
// bool DetectType::isInteger(const std::string& s) {
//     char* p;
//     std::strtol(s.c_str(), &p, 10);
//     return *p == '\0';
// }
*/

bool DetectType::isInteger(const std::string& str)
{
    int i = 0;
    while (i < str.length() && isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

bool DetectType::isFloat(const std::string& str)
{
    int i = 0;
    bool float_flag = false;
    bool found_dot = false;
    if (str == "-inff" || str == "-inff" || str == "nanf")
        return true;
    while (i < str.length() && isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.length(); i++)
    {
        if ((!isdigit(str[i]) && str[i] != 'f' && str[i] != '.')
            || (str[i] == 'f' && float_flag)
            || (str[i] == '.' && found_dot))
            return false;
        if (str[i] == 'f')
            float_flag = true;
        else if (str[i] == '.')
            found_dot = true;
    }
    return true;
}

bool DetectType::isDouble(const std::string& str)
{
    int i = 0;
    bool found_dot = false;
    if (str == "-inf" || str == "-inf" || str == "nan")
        return true;
    while (i < str.length() && isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.length(); i++)
    {
        if ((!isdigit(str[i]) && str[i] != '.')
            || (str[i] == '.' && found_dot))
            return false;
        if (str[i] == '.')
            found_dot = true;
    }
    return true;
}

Type DetectType::detect_type(const std::string& str)
{
    if (str[0] == '\'')
        return str.length() == 1 ? CHAR : NONE;
    else if (DetectType::isInteger(str))
        return INT;
    else if (DetectType::isFloat(str))
        return FLOAT;
    else if (DetectType::isDouble(str))
        return DOUBLE;
    else
        return NONE;
}
