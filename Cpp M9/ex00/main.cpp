# include "BitcoinExchange.hpp"

static int inputFileValidity(const char* inputFile, const BitcoinExchange& btc) {
    std::ifstream infile;
    std::string readedLine;
    infile.open(inputFile, std::ios::in);
    if (!infile) {
        std::cerr << "Error: Failed To Open The File" << std::endl;
        return 1;
    }
    getline(infile, readedLine);
    while (getline(infile, readedLine)) {
        if (inputFileProcess(readedLine, btc))
            return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "The Program should have One Argument [Format]: ./btc filename.csv" << std::endl;
        return 1;
    }
    // Need to open the file first here from argv[1] to check for errors

    const std::string filename = "./data.csv";
    try {
        BitcoinExchange Btc(filename);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}