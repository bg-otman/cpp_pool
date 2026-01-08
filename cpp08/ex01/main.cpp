#include "Span.hpp"

int main()
{
    std::cout << "--- Test 1: Subject Example ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << " (Expected: 14)" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Exceptions ---" << std::endl;
    try {
        Span small(1);
        small.addNumber(10);
        std::cout << "Trying to add to full span... ";
        small.addNumber(20);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Span empty(5);
        std::cout << "Trying span on empty... ";
        std::cout << empty.shortestSpan();
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Range Insertion ---" << std::endl;
    try {
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(100);
        numbers.push_back(50);
        
        Span rangeSpan(5);

        rangeSpan.addRange(numbers.begin(), numbers.end()); 
        
        std::cout << "Vector Shortest: " << rangeSpan.shortestSpan() << " (Expected: 49)" << std::endl;
        std::cout << "Vector Longest:  " << rangeSpan.longestSpan() << " (Expected: 99)" << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
