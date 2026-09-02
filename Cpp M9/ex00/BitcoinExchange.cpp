# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "Default Constructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : dataBase(other.dataBase) {
    std::cout << "Copy Constructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    std::ifstream dataFile;
    dataFile.open(filename.c_str(), std::ios::in);
    if (!dataFile)
        throw std::runtime_error("Error: Failed To Open Data.csv File");
    
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "Destrcutor Called" << std::endl;
}

float BitcoinExchange::rateBasedDate(const std::string& query) const {

}