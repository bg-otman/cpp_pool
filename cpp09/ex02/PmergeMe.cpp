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

void    PmergeMe::merge(std::vector<int>& arr, size_t left, size_t mid, size_t right) const
{
    size_t left_size = mid - left + 1;
    size_t right_size = right - mid;
    size_t i = 0;
    size_t j = 0;
    size_t k = left;
    std::vector<int> tmp_left(left_size), tmp_right(right_size);

    for (; i < left_size; i++)
        tmp_left[i] = arr[left + i];
    for (; j < right_size; j++)
        tmp_right[j] = arr[mid + j + 1];

    i = 0, j = 0;
    while (i < left_size && j < right_size)
    {
        if (tmp_left[i] <= tmp_right[j])
            arr[k++] = tmp_left[i++];
        else
            arr[k++] = tmp_right[j++];
    }

    while (i < left_size)
        arr[k++] = tmp_left[i++];
    while (j < right_size)
        arr[k++] = tmp_right[j++];
}

void    PmergeMe::merge_sort(std::vector<int>& arr, size_t left, size_t right) const
{
    if (left >= right)
        return ;
    size_t mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void	print_vec( std::vector<int>& v) // tmp fun, i need to remove it
{
    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::create_chains(std::vector<int>& main, std::vector<int>& pending) const
{
    int p1, p2;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _vector.size(); i += 2)
    {
        p1 = _vector[i];
        p2 = _vector[i + 1];

        if (p1 <= p2)
            pairs.push_back(std::make_pair(p1, p2));
        else
            pairs.push_back(std::make_pair(p2, p1));

        // pending.push_back(std::min(p1, p2));
        // main.push_back(std::max(p1, p2));
    }
    // merge_sort(main, 0, main.size() - 1);
    
    for (size_t i = 0; i < pairs.size(); i++)
    {
        main.insert(main.begin(), pairs[i].second);
        pending.insert(pending.begin(), pairs[i].first);
    }
    

    std::cout << "main chain : ";
    print_vec(main);
    std::cout << "pending chain : ";
    print_vec(pending);
}

/*
main chain : 4 6 8 
pending chain : 2 5 3 
*/

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
