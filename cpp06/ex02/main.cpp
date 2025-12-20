#include "Base.hpp"

int main() {

    Base* p = generate();
    Base& p_ref = *p;

    std::cout << "identify using pointer : ";
    identify(p);
    std::cout << "identify using ref : ";
    identify(p_ref);


    std::cout << "\n---TEST INVALID TYPE---" << std::endl;
    Base* p2 = NULL;
    Base& p2_ref = *p2;

    std::cout << "identify using pointer : ";
    identify(p2);
    std::cout << "identify using ref : ";
    identify(p2_ref);

    delete p;
    return 0;
}
