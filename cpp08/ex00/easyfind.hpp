#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
std::vector<int>::iterator easyfind(T c, int n)
{
    // std::cout << "-" << *(c.begin()) << "-\n";
    return std::find(c.begin(), c.end(), n);
}

#endif
