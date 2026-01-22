#include "RPN.hpp"

int main(int ac, char* av[])
{
    if (ac != 2)
    {
        std::cerr << "Error : invalid args. ex: ./RPN \"NUM NUM EXP\"" << std::endl;
        return 1;
    }
    RPN rpn(av[1]);
    rpn.process_expression();
    return 0;
}
