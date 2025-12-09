#ifndef DEFINETYPE_HPP
#define DEFINETYPE_HPP

#include "ScalarConverter.hpp"

class DetectType
{
    private:
        DetectType();
        DetectType(const DetectType& obj);
        DetectType& operator=(const DetectType& obj);
        ~DetectType();
    public:
        static bool isInteger(const std::string& str);
        static bool isFloat(const std::string& str);
        static bool isDouble(const std::string& str);
        static Type detect_type(const std::string& str);
};

#endif
