#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
	: _data(obj._data), _input(obj._input)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    if (this != &obj)
    {
        this->_data = obj._data;
		this->_input = obj._input;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const char* input)
	: _input(input)
{
}

void    BitcoinExchange::trim(std::string& str) const
{
    if (str.empty())
        return ;
    int i = 0;
    while (str[i] && std::isspace(str[i])) ++i;
    if (!str[i]){
        str = "";
        return ;
    }
    int j = str.length() - 1;
    while (j > 0 && std::isspace(str[j])) --j;
    str = str.substr(i, j - i + 1);
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
        trim(token);
        if (i == 0)
            year = static_cast<int>(strtof(token.c_str(), &end));
        else if (i == 1)
            month = static_cast<int>(strtof(token.c_str(), &end));
        else
            day = static_cast<int>(strtof(token.c_str(), &end));
		if (*end != '\0' || (i == 0 && token.size() != 4) || (i >= 1 && token.size() != 2))
			return false;
        i++;
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

bool   BitcoinExchange::is_valid_rate(std::string rate) const
{
    errno = 0;
    char* endptr;

    float num = strtof(rate.c_str(), &endptr);
    if (errno == ERANGE || num > 1000)
		std::cout << "Error: too large a number." << std::endl;
    else if (*endptr != '\0')
        std::cout << "Error: bad input => Not number" << std::endl;
    else if (num < 0)
		std::cout << "Error: not a positive number." << std::endl;
	return ((errno == ERANGE || num > 1000 || *endptr != '\0' || num < 0) ? false : true);
}

void    BitcoinExchange::print_price(std::string date, float rate)
{
    trim(date);
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

void    BitcoinExchange::read_database( void )
{
    std::ifstream db("data.csv");
    std::string line, date, rate;

    if (!db.is_open())
        throw std::runtime_error("Error: could not open **data** file.");
    if (!std::getline(db, line) || line != "date,exchange_rate")
        throw std::runtime_error("Error: Invalid header");
    while (std::getline(db, line))
    {
        date = line.substr(0, line.find_first_of(","));
        rate = line.substr(line.find_first_of(",") + 1);
        _data[date] = strtof(rate.c_str(), NULL);
    }
	db.close();
}

void    BitcoinExchange::get_btc_price( void )
{
    std::string line, date, rate;
	std::ifstream in_file(_input.c_str());

	read_database();
	if (!in_file.is_open())
    	throw std::runtime_error("Error: could not open **input** file.");
    if (!std::getline(in_file, line) || line != "date | value")
        throw std::runtime_error("Error: Invalid header in input file");
    while (std::getline(in_file, line))
    {
        trim(line);
        date = line.substr(0, line.find_first_of("|"));
        rate = line.substr(line.find_first_of("|") + 1);
        if (line.empty())
            continue;
		else if (rate.empty() || !is_valid_date(date)
				|| std::count(line.begin(), line.end(), '|') != 1)
			std::cout << "Error: bad input => " << line << std::endl;
        else if (is_valid_rate(rate))
            print_price(date, strtof(rate.c_str(), NULL));
    }
	in_file.close();
}
