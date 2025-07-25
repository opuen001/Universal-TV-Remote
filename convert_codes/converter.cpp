#include "EncodeIR.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream inputFile("irdbCodes/vizio.csv");
    std::ofstream outputFile("../rawTimings/vizioTimings.csv");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files.\n";
        return 1;
    }

    std::string line;
    bool first = true;
    // Read each line from input csv
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string function, protocal;
        int d, s, f;
        char commas;

        if (first){
            //ignores the header in each file
            std::getline(ss,function, '\n');
            first = false;
        } else{
            // get the function name and information
            std::getline(ss, function, ',');
            std::getline(ss, protocal, ',');
            ss >> d >> commas >> s >> commas >> f;

            //create a char* for EncodeIR
            std::vector<char> prot_char(protocal.begin(), protocal.end());
            prot_char.push_back('\0');

            std::string timings = EncodeIR(prot_char.data(), d, s, f);

            //Output raw timings to new csv
            outputFile << function << ": " << timings << "\n";
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Done copying CSV.\n";
    return 0;
}
