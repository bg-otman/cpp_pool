#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <deque>
#include <boost/algorithm/string.hpp>
#include <exception>
#include <sstream>
#include <climits>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        std::string _nums;

        void    print_elements( void ) const;
        void    create_chains(std::vector<int>& main, std::vector<int>& pending) const;
        void    merge_sort(std::vector<int>& arr) const;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        PmergeMe(const char *nums);
        void    fordJohnsonSort( void );
};

#endif
