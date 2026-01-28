#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& obj)
    : _vector(obj._vector), _deque(obj._deque), _nums(obj._nums)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    if (this != &obj)
    {
        this->_vector = obj._vector;
        this->_deque = obj._deque;
        this->_nums = obj._nums;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const char *nums)
    : _nums(nums)
{
    if (_nums.empty())
        throw std::runtime_error("Error");
    std::stringstream stream(_nums);
    std::string line;
    long nb = 0;
    char *end;
    while (std::getline(stream, line, ' '))
    {
		boost::trim(line);
        if (line.empty())
            continue;
        nb = std::strtol(line.c_str(), &end, 10);
        if (nb > INT_MAX || nb < INT_MIN || *end != '\0')
            throw std::runtime_error("Error");
        else if (nb < 0)
            throw std::runtime_error("Error: only positive number allowed");
        _vector.push_back(static_cast<int>(nb));
        _deque.push_back(static_cast<int>(nb));
    }
}

int PmergeMe::jackobsthal_nums(int n) const
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return jackobsthal_nums(n - 1) + 2 * jackobsthal_nums(n - 2);
}

// return num <= to num in jackobsthal sequence
int PmergeMe::get_jackobsthal_num(int num) const
{
    int result = 1, previous = 1;
    for (int i = 0; i <= num; i++)
    {
        result = jackobsthal_nums(i);
        if (result > num)
            return previous;
        else if (result == num)
            return result;
        previous = result;
    }
    return result;
}

std::vector<int>	PmergeMe::sort_vector( std::vector<int> arr )
{
    if (arr.size() <= 1)
        return arr;
    bool isOdd;
    int leftOver;
    isOdd = arr.size() % 2 ? true : false;
    if (isOdd)
    {
        leftOver = arr[arr.size() - 1];
        arr.pop_back();
    }
    std::vector<int> big_nums, small_nums;
    
    // separate_pairs
    int p1, p2;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        p1 = arr[i];
        p2 = arr[i + 1];
        small_nums.push_back(std::min(p1, p2));
        big_nums.push_back(std::max(p1, p2));
    }

    std::vector<int> main_chain = sort_vector(big_nums); // sort big nums recursively
    std::vector<int> pending;

    // this loop push the small_nums to pending according to the order of big_nums in main_chain
    for (size_t i = 0; i < main_chain.size(); i++)
    {
        int element = main_chain[i];
        for (size_t j = 0; j < big_nums.size(); j++)
        {
            if (big_nums[j] == element)
            {
                pending.push_back(small_nums[j]);
                big_nums[j] = -1;
                break;
            }
        }
    }
    if (isOdd)
        pending.push_back(leftOver);
    // binary_insertion
    std::vector<int> insert_order;
    size_t size = pending.size();
    std::vector<int>::iterator pos;
    int to_insert;

    main_chain.insert(main_chain.begin(), pending[0]);
    get_insertion_order(insert_order, size);
    for (size_t i = 1; i < size; i++)
    {
        to_insert = pending[insert_order[i] - 1];
        pos = std::upper_bound(main_chain.begin(), main_chain.end(), to_insert);
        main_chain.insert(pos, to_insert);
    }

    return main_chain;
}

std::deque<int>	PmergeMe::sort_deque( std::deque<int> arr )
{
    if (arr.size() <= 1)
        return arr;
    bool isOdd;
    int leftOver;
    isOdd = arr.size() % 2 ? true : false;
    if (isOdd)
    {
        leftOver = arr[arr.size() - 1];
        arr.pop_back();
    }
    std::deque<int> big_nums, small_nums;
    
    // separate_pairs
    int p1, p2;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        p1 = arr[i];
        p2 = arr[i + 1];
        small_nums.push_back(std::min(p1, p2));
        big_nums.push_back(std::max(p1, p2));
    }

    std::deque<int> main_chain = sort_deque(big_nums); // sort big nums recursively
    std::deque<int> pending;

    // this loop push the small_nums to pending according to the order of big_nums in main_chain
    for (size_t i = 0; i < main_chain.size(); i++)
    {
        int element = main_chain[i];
        for (size_t j = 0; j < big_nums.size(); j++)
        {
            if (big_nums[j] == element)
            {
                pending.push_back(small_nums[j]);
                big_nums[j] = -1;
                break;
            }
        }
    }
    if (isOdd)
        pending.push_back(leftOver);
    // binary_insertion
    std::deque<int> insert_order;
    size_t size = pending.size();
    std::deque<int>::iterator pos;
    int to_insert;

    main_chain.push_front(pending[0]);
    get_insertion_order(insert_order, size);
    for (size_t i = 1; i < size; i++)
    {
        to_insert = pending[insert_order[i] - 1];
        pos = std::upper_bound(main_chain.begin(), main_chain.end(), to_insert);
        main_chain.insert(pos, to_insert);
    }

    return main_chain;
}

void    PmergeMe::fordJohnsonSort( void )
{
    _vector = sort_vector(_vector);
    _deque = sort_deque(_deque);
    std::cout << "vector:" << std::endl;
    print_elements(_vector);
    std::cout << "deque:" << std::endl;
    print_elements(_deque);
}
