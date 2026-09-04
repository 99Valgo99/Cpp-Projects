# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <sstream>
# include <ctime>
# include <cstdlib>

class BitcoinExchange {
    private:
        BitcoinExchange();
        std::map<std::string, float> dataBase;
    public:
        BitcoinExchange(const std::string& filename);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        float rateBasedDate(const std::string& query) const;
};
    
bool dateValidation(const std::string& date);
bool valueValidation(const std::string& value, float& getvValue);

# endif