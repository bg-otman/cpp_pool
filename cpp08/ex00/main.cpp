#include "easyfind.hpp"

int main( void )
{
    std::vector<int> nums;
    for (int i = 10; i < 15; i++)
        nums.push_back(i);

    std::cout << *(nums.begin()) << std::endl;
    std::cout << *(nums.end()) << std::endl;
    

    int needle = 4;
    // if (easyfind(nums, needle) == nums.end())
    //     std::cout << "The container doesn't contain : " << needle << std::endl;
    // else
    //     std::cout << "Easy Find : " << needle << std::endl;

    std::cout << "[" << *easyfind(nums, needle) << "]\n";

    return 0;
}
