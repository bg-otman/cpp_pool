#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "Invalid number of arguments" << std::endl;
        std::cerr << "REQUIRED FORMAT : ./convert [TYPE : CHAR, INT, FLOAT OR DOUBLE]. ex: ./convert 97" << std::endl;
        std::cerr << "NOTE FOR CHAR IT MUST BE WITH THIS FORMAT : ex: ./convert \"\'a'\"" << std::endl;
        return 1;
    }
    const std::string str = av[1];
    ScalarConverter::convert(str);
    return 0;
}
