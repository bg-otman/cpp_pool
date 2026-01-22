#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stack>

class RPN
{
    private:
        std::stack<int> _stack;
        std::string _exp;

        bool    is_valid_operator(char c) const;
        int		calculate(int first, int second, char op) const;
    public:
        RPN();
        RPN(const RPN& obj);
        RPN& operator=(const RPN& obj);
        ~RPN();

        RPN(const char* expression);
        void    process_expression( void );
};

#endif
