#include "EncodeIR.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream inputFile("irdbCodes/vizio.csv");
    std::ofstream outputFile("irdbCodes/output.csv");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files.\n";
        return 1;
    }

    std::string line;

    // Read each line from input.csv
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        // Split line by commas
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        // Example: write same row to output.csv
        for (size_t i = 0; i < row.size(); ++i) {
            outputFile << row[i];
            if (i < row.size() - 1)
                outputFile << ",";
        }
        outputFile << "\n";
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Done copying CSV.\n";
    return 0;
}
