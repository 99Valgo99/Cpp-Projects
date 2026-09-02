# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <stdexcept>
# include <fstream>

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


# endif