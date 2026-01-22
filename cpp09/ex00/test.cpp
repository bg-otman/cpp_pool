#include "BitcoinExchange.hpp"
// #include <boost/regex.hpp>

// int main()
// {
//     // std::string line;
//     // std::ifstream in("input.csv");
//     // bool b = static_cast<bool> (std::getline(in, line));
//     // std::cout << "bool : {" << b << "}" << std::endl;
//     // std::cout << "empty : " << line.empty() << std::endl;
//     // std::cout << line << std::endl;

//     std::string s = "2020-022-01";
//     boost::regex pattern("(\\d{4}[- ]){3}\\d{4}");
//     bool result = boost::regex_match(s, pattern);
//     std::cout << "result : " << std::endl;
//     return 0;
// }


bool    is_valid_rate(std::string rate)
{
    errno = 0;
    char* endptr;

    float num = strtof(rate.c_str(), &endptr);
    if (endptr == rate)
        return false;
    return true;
}

int main()
{
    // // std::string str("    Hello, World!              \t");
    // // boost::trim(str);
    // // std::cout << "result : {" << str << "}" << std::endl;

    // std::list<std::string> l;
    // boost::split(l, "Hello-world-hey,", boost::is_any_of(","));
    // std::cout << l.size();

    std::cout << is_valid_rate("10.2");
    return 0;
}
