#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    if (this != &obj)
    {
        
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    _input.close();
}

BitcoinExchange::BitcoinExchange(const char* input)
    : _input(input)
{
    if (!_input.is_open())
        throw std::runtime_error("Error: could not open **input** file.");
}

bool    BitcoinExchange::is_valid_date(std::string date) const
{
    if (std::count(date.begin(), date.end(), '-') != 2)
        return false;
    struct tm tm = {};
    std::string token;
    std::stringstream str(date);
    int year = 0, month = 0, day = 0, i = 0;
    char* end;
    while (std::getline(str, token, '-'))
    {
        boost::trim(token);
        if (i == 0)
            year = static_cast<int>(strtof(token.c_str(), &end));
        else if (i == 1)
            month = static_cast<int>(strtof(token.c_str(), &end));
        else
            day = static_cast<int>(strtof(token.c_str(), &end));
        i++;
        if (*end != '\0')
            return false;
    }
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    time_t time = std::mktime(&tm);
    if (time == -1 
        || !(tm.tm_year == year - 1900
            && tm.tm_mon == month - 1
            && tm.tm_mday == day)
    	|| month == 0
        || day == 0)
        return false;
    return true;
}

bool   BitcoinExchange::is_valid_rate(std::string rate, BadNum& reason) const
{
    errno = 0;
    char* endptr;
    reason = NONE;

    float num = strtof(rate.c_str(), &endptr);
    if (errno == ERANGE)
        reason = BIG_NUM;
    else if (*endptr != '\0')
        reason = NOT_NUM;
    else if (num < 0)
        reason = NEGATIVE_NUM;

    if (reason == NONE && num > 1000)
    {
        reason = BIG_NUM;
        return true;
    }
    else
        return reason == NONE ? true : false;
}

void    BitcoinExchange::read_database( void )
{
    std::ifstream db("data.csv");
    std::string line, date, rate;
    BadNum reason;

    if (!db.is_open())
        throw std::runtime_error("Error: could not open **data** file.");
    if (!std::getline(db, line) || line != "date,exchange_rate")
        throw std::runtime_error("Error: Invalid header");
    while (std::getline(db, line))
    {
        boost::trim(line);
        date = line.substr(0, line.find_first_of(","));
        rate = line.substr(line.find_first_of(",") + 1);
        if (line.empty() || std::count(line.begin(), line.end(), ',') != 1
            || !is_valid_date(date)
            || !is_valid_rate(rate, reason))
            continue;
        _data[date] = strtof(rate.c_str(), NULL);
    }
}

void    BitcoinExchange::print_price(std::string date, float rate)
{
    boost::trim(date);
    std::map<std::string, float>::iterator it_price = _data.lower_bound(date);
    if (it_price == _data.end() || it_price->first > date)
    {
        if (it_price == _data.begin())
        {
            std::cout << "Error : Can't find any info at this date => " << date << std::endl;
			return ;
        }
        --it_price;
    }
    std::cout << date << " => " << rate << " = " << rate * (it_price->second) << std::endl;
}

void    BitcoinExchange::get_btc_price( void )
{
    std::string line, date, rate;
    BadNum reason;

    if (!std::getline(_input, line) || line != "date | value")
        throw std::runtime_error("Error: Invalid header");
    while (std::getline(_input, line))
    {
        boost::trim(line);
        date = line.substr(0, line.find_first_of("|"));
        rate = line.substr(line.find_first_of("|") + 1);
        if (line.empty())
            continue;
        else if (!is_valid_date(date))
            std::cout << "Error: bad input => " << date << std::endl;
        else if (std::count(line.begin(), line.end(), '|') != 1)
            std::cout << "Error: bad input => invalid format (ex: date | value)." << std::endl;
        else if (!is_valid_rate(rate, reason) || reason == BIG_NUM)
        {
            if (reason == NEGATIVE_NUM)
                std::cout << "Error: not a positive number." << std::endl;
            else if (reason == BIG_NUM)
                std::cout << "Error: too large a number." << std::endl;
            else
                std::cout << "Error: bad input => Not number" << std::endl;
        }
        else
            print_price(date, strtof(rate.c_str(), NULL));
    }
}
