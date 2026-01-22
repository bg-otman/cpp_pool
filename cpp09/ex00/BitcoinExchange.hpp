#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <exception>
#include <boost/algorithm/string.hpp>
#include <cerrno>
#include <cstdlib>

enum BadNum
{
        NONE,
        BIG_NUM,
        NOT_NUM,
        NEGATIVE_NUM
};

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;
        std::ifstream _input;
        
        bool    is_valid_date(std::string date) const;
        bool    is_valid_rate(std::string rate, BadNum& reason) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();

        BitcoinExchange(const char* input);
        void    read_database( void );
        void    get_btc_price( void );
        void    print_price(std::string date, float rate);
        
};


#endif
