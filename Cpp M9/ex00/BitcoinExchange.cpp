# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "Default Constructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : dataBase(other.dataBase) {
    std::cout << "Copy Constructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    std::ifstream dataFile;
    std::string readedLine;
    dataFile.open(filename.c_str(), std::ios::in);
    if (!dataFile)
        throw std::runtime_error("Error: Failed To Open Data.csv File");
    getline(dataFile, readedLine);
    while (getline(dataFile, readedLine)) {
        size_t splitData = readedLine.find(',');
        if (splitData == std::string::npos)
            continue;
        std::string date = readedLine.substr(0, splitData);
        std::string value = readedLine.substr(splitData + 1);
        float rate;
        if (!dateValidation(date) || !valueValidation(value, rate))
            continue;
        dataBase.insert(std::make_pair(date, rate));
    }
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
    std::map<std::string, float>::const_iterator it = dataBase.lower_bound(query);
    if (it != dataBase.end() && it->first == query)
        return it->second;
    if (it == dataBase.begin())
        throw std::runtime_error("Error: No Rate For This Date");
    --it;
    return it->second;
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

bool valueValidation(const std::string& value, float& getvValue) {
    char *endchar = 0;

    if (value.empty())
        return false;
    double res = std::strtod(value.c_str(), &endchar);
    if (*endchar != '\0' || res < 0)
        return false;
    else
        getvValue = res;
    return true;
}

void inputFileProcess(const std::string& readedLine, const BitcoinExchange& btc) {
    size_t pipeline = readedLine.find('|');
    if (pipeline == std::string::npos) {
        std::cerr << "Error: bad input => " << readedLine << std::endl;
        return ;
    }
    std::string date = readedLine.substr(0, pipeline);
    std::string value = readedLine.substr(pipeline + 1);
    // to trim
    float valuefloated;
    if (!dateValidation(date)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return ;
    }
    bool numberFigure = !value.empty() && (std::isdigit(value[0])
        || value[0] == '-' || value[0] == '+');
    if (!numberFigure) {
        std::cerr << "Error: bad input => " << value << std::endl;
        return ;
    }
    if (!valueValidation(value, valuefloated)) {
        std::cerr << "Error: not a positive number." << std::endl;
        return ;
    }
    if (valuefloated > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return ;
    }
    try {
        float rate = btc.rateBasedDate(date);
        std::cout << date << " => " << valuefloated << " = " << (valuefloated * rate) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return ;
}