#include <iostream>
#include <fstream>
#include <string>

std::ifstream inputFile;
std::ofstream outputFile;

int main() {
    std::string inputFileName, outputFileName, line;

    std::cout << "Input file: ";
    std::cin >> inputFileName;
    std::cout << "Output file: ";
    std::cin >> outputFileName;
    inputFile.open(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error! The file " << inputFileName << " cannot be opened.\n";
        return EXIT_FAILURE;
    }
    outputFile.open(outputFileName);
    int lineNumber = 1;
    while (std::getline(inputFile, line)) {
        outputFile << lineNumber++ << " " << line << "\n";
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
