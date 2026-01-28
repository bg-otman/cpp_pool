#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
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

        std::vector<int>    fordJohnsonSort( std::vector<int> arr );
        void                separate_pairs(std::vector<int>& main, std::vector<int>& pending, std::vector<int> arr) const;
        void                binary_insertion(std::vector<int>& main_chain, std::vector<int>& pending) const;
        void                get_insertion_order(std::vector<int>& insertion_order, int size) const;
        int                 jackobsthal_nums(int n) const;
        int                 get_jackobsthal_num(int num) const;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        PmergeMe(const char *nums);
        void    print_elements( void ) const;
        void    sort( void );
};

#endif
