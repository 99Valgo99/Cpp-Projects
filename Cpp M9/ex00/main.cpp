# include "BitcoinExchange.hpp"

static void inputFileValidity(const char* inputFile, const BitcoinExchange& btc) {
    std::ifstream infile;
    std::string readedLine;
    infile.open(inputFile, std::ios::in);
    if (!infile) {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }
    getline(infile, readedLine);
    while (getline(infile, readedLine)) {
        inputFileProcess(readedLine, btc);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    const std::string filename = "./data.csv";
    try {
        BitcoinExchange Btc(filename);
        inputFileValidity(argv[1], Btc);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}