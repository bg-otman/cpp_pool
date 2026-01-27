#include "PmergeMe.hpp"

int main(int ac, char* av[])
{
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pmerge(av[1]);
        pmerge.fordJohnsonSort();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 2;
    }
    return 0;
}
