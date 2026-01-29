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
#include <cerrno>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;
        std::string _input;
        
        bool    is_valid_date(std::string date) const;
        bool    is_valid_rate(std::string rate) const;
        void    print_price(std::string date, float rate);
        void    read_database( void );
        void    trim(std::string& str) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();

        BitcoinExchange(const char* input);
        void    get_btc_price( void );
};


#endif
