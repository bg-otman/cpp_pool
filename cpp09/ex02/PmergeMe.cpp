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

void	PmergeMe::print_elements( void ) const
{
    for (std::vector<int>::const_iterator i = _vector.begin(); i != _vector.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
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

void    PmergeMe::merge_sort(std::vector<int>& arr) const
{

}

void    PmergeMe::create_chains(std::vector<int>& main, std::vector<int>& pending) const
{
    int pair1, pair2;
    for (size_t i = 0; i < _vector.size(); i += 2)
    {
        pair1 = _vector[i];
        pair2 = _vector[i + 1];
        pending.push_back(std::min(pair1, pair2));
        main.push_back(std::max(pair1, pair2));
    }
}

void	PmergeMe::fordJohnsonSort( void )
{
    std::vector<int> main_chain, pending;
    bool isOdd;
    int leftOver;
    
    isOdd = _vector.size() % 2 ? true : false;
    if (isOdd)
    {
        leftOver = _vector[_vector.size() - 1];
        _vector.pop_back();
    }
    create_chains(main_chain, pending);

}
