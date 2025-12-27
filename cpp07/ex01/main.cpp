#include "iter.hpp"

void printData(const std::string& e)
{
    std::cout << "--> " << e << std::endl;
}

void setHello(std::string& e)
{
    e = "HELLO";
}

int main( void )
{
    std::string strs[] = {"Holla", "Hello", "WORLD", "world"};
    const size_t len = 4;

    iter(strs, len, printData);
    iter(strs, len, setHello);
    std::cout << std::endl;
    iter(strs, len, printData);
    return 0;
}
