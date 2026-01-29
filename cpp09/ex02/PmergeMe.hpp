#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>
#include <deque>
#include <exception>
#include <cerrno>
#include <climits>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        std::vector<int>    sort_vector( std::vector<int> arr );
        std::deque<int>     sort_deque( std::deque<int> arr );
        void                trim(std::string& str) const;
        int                 jackobsthal_nums(int n) const;
        int                 get_jackobsthal_num(int num) const;

        template <class T> void    fill_gap(T& insertion_order, int start, int end) const;
        template <class T> void    get_insertion_order(T& insertion_order, int size) const;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        PmergeMe(char *nums[]);
        void    fordJohnsonSort( void );
};

template <class T>
void    PmergeMe::fill_gap(T& insertion_order, int start, int end) const
{
    while (end > start)
    {
        insertion_order.push_back(end);
        end--;
    }
}

template <class T>
void    PmergeMe::get_insertion_order(T& insertion_order, int size) const
{
    int i = 1, previous = 0, order;
    while (i < size)
    {
        order = get_jackobsthal_num(i);
        if (order > size)
            break;
        if (order > previous)
        {
            fill_gap(insertion_order, previous, order);
            previous = order;
        }
        i++;
    }
    fill_gap(insertion_order, previous, size);
}

#endif
