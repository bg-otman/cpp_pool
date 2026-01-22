#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& obj)
    : _stack(obj._stack), _exp(obj._exp)
{
}

RPN& RPN::operator=(const RPN& obj)
{
    if (this != &obj)
    {
        this->_stack = obj._stack;
        this->_exp = obj._exp;
    }
    return (*this);
}

RPN::~RPN()
{
}

RPN::RPN(const char* expression)
    : _exp(expression)
{
}

bool    RPN::is_valid_operator(char c) const
{
    return (c == '+' || c == '-' ||
            c == '/' || c == '*');
}

int RPN::calculate(int first, int second, char op) const
{
    int result = 0;
    switch (op)
    {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '/':
            result = first / second;
            break;
        case '*':
            result = first * second;
            break;
        default:
            break;
    }
    return result;
}

void display_stack(std::stack<int> st) {
    while (!st.empty()) {
        std::cout << st.top() << ", ";
        st.pop();
    }
    std::cout << std::endl;
}

void    RPN::process_expression( void )
{
    int first, second, result;
    bool error = false;
    for (size_t i = 0; i < _exp.size(); i++)
    {
        if (is_valid_operator(_exp[i]) && _stack.size() >= 2)
        {
            second = _stack.top();
            _stack.pop();
            first = _stack.top();
            _stack.pop();
            result = calculate(first, second, _exp[i]);
            _stack.push(result);
        }
        else if (isdigit(_exp[i]))
            _stack.push(_exp[i] - '0');
        else if (!isspace(_exp[i]))
        {
            error = true;
            break;
        }
    }
    if (_stack.size() != 1 || error)
        std::cerr << "ERROR" << std::endl;
    else
        std::cout << _stack.top() << std::endl;
}
