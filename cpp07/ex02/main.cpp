#include "Array.hpp"

int main( void )
{
    Array<int> a(3);


    // int * a = new int();
    try
    {
        std::cout << "-->" << a[1] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
