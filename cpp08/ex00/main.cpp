#include "easyfind.hpp"

int main( void )
{
    std::vector<int> nums;
    for (int i = 0; i < 5; i++)
        nums.push_back(i);

    std::cout << "Numbers in the container are : ";
    std::vector<int>::iterator n = nums.begin();
    for (; n != nums.end(); n++)
        std::cout << *n << " ";
    std::cout << std::endl;

    int needle = 2;
    try
    {
        easyfind(nums, needle);
        needle -= 2;
        easyfind(nums, needle);
        needle += 8;
        easyfind(nums, needle);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
