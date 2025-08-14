#ifndef IR_SENDER_H
#define IR_SENDER_H
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>

class IrSender{
    private:
    int LED_PIN;
    std::vector<std::vector<int>> codes;
    std::vector<std::string> functionOrder;
    const std::string files[10] = {"../rawTimings/vizioTimings.csv", "../rawTimings/aocTimings.csv", "../rawTimings/aristonaTimings.csv", 
        "../rawTimings/bekoTimings.csv", "../rawTimings/bushTimings.csv", "../rawTimings/grundigTimings.csv", "../rawTimings/hitachiTimings.csv",
        "../rawTimings/hyundaiTimings.csv", "../rawTimings/jvcTimings.csv", "../rawTimings/LGTimings.csv"};
    void modulation(unsigned int timeMicros); //modulates the signal at 38kHz

    public:
    void getCodes(const std::string& fileName); //Loads in the IR codes from the provided rawTimings file

    void getCodes(const int fileIndex); //Loads in the IR codes from the file at the index

    void printFunctionOrder(); //Prints the index of each code for the function

    void clearCodes(); //Clears all loaded codes, not necessary to run before getCodes

    void sendIrCode(const int codeIndex); //Outputs the IR signal from the designated index
};

#endif