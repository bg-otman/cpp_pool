#include "MutantStack.hpp"

void printStack(MutantStack<std::string>& stack) {
    for (MutantStack<std::string>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main( void )
{
    // ------ Subject Example ------- //
    std::cout << "-----Subject Example------" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // ------ Test as the subject descriped ----- //
    std::cout << "-----COMPARE WITH LIST------" << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);
    std::list<int>::iterator it_list = mlist.begin();
    std::list<int>::iterator ite_list = mlist.end();
    ++it_list;
    --it_list;
    while (it_list != ite_list)
    {
        std::cout << *it_list << std::endl;
        ++it_list;
    }

    // ------  ----- //
    std::cout << "-----Const Iterator TEST------" << std::endl;
    MutantStack<std::string> strs;
    strs.push("Hello1");
    strs.push("Hello2");
    strs.push("Hello3");
    printStack(strs);

    // ------  ----- //
    std::cout << "-----Reverse Iterator TEST------" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    return 0;
}

