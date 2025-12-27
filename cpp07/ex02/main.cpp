#include "Array.hpp"

int main()
{
    Array<int> arr(5);
    Array<std::string> strArr;

    std::cout << "empty string array size: " << strArr.size() << std::endl;
    
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i;

    std::cout << "access integer arr[3] = " << arr[3] << std::endl;

    // Deep Copy Test
    std::cout << "\n--- 2. Deep Copy Test ---" << std::endl;
    Array<int> copy = arr;
    
    arr[3] = 99; // Change the ORIGINAL array only
    
    std::cout << "Original [3]: " << arr[3]  << " (Expected: 99)" << std::endl;
    std::cout << "Copy     [3]: " << copy[3] << " (Expected: 3)"  << std::endl;

    // Exception Test (Out of Bounds)
    std::cout << "\n--- 3. Exception Test ---" << std::endl;
    try {
        std::cout << "Accessing index 100..." << std::endl;
        std::cout << arr[100] << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << "Caught error: " << e.what() << std::endl;
    }

    return 0;
}