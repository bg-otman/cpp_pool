#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

template<typename T>
int easyfind(T container, int n)
{
    std::cout << "Looking for : " << n << std::endl;
    if (std::find(container.begin(), container.end(), n) == container.end())
        throw std::runtime_error("Cannot find it");
    else
        std::cout << "Easy Find : " << n << std::endl;
    return n;
}

#endif
