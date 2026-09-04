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

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->dataBase = other.dataBase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "Destrcutor Called" << std::endl;
}

float BitcoinExchange::rateBasedDate(const std::string& query) const {
    
}

bool dateValidation(const std::string& date) {
    
    int day = 0;
    int year = 0;
    int month = 0;
    std::string token;
    int tokenPassed = 0;
    bool caseOne = false;
    bool caseTwo = false;
    std::stringstream streamString(date);

    if (date.length() != 10)
        return false;

    while (std::getline(streamString, token, '-')) {
        if (tokenPassed == 0)
            year = std::atoi(token.c_str());
        else if (tokenPassed == 1)
            month = std::atoi(token.c_str());
        else if (tokenPassed == 2)
            day = std::atoi(token.c_str());
        for (int i = 0; i < token.size(); i++) {
            if (!std::isdigit(token[i]))
                return false;
            if (tokenPassed == 1 && token == "02")
                caseOne = true;
            if (tokenPassed == 1 && (token == "04" || token == "06"
                    || token == "09" || token == "11"))
                caseTwo = true;
        }
        tokenPassed++;
    }
    if ((day == 30 || day == 31) && caseOne == true)
        return false;
    if (day == 31 && caseTwo == true)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (month > 12 || 1 > month)
        return false;

    std::time_t t = std::time(0);
    std::tm* current = std::localtime(&t);
    int nowYear = current->tm_year + 1900;

    if (year < 1 || year > nowYear)
        return false;
    return true;
}