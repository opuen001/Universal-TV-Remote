#include "IrSender.h"
#include <string>


void IrSender::getCodes(const std::string& fileName){
    std::ifstream inputFile(fileName);

    //try variations of the file name before giving up
    if(!inputFile.is_open()){
        std::string fileError = "/rawTimings/" + fileName;
        inputFile.close();
        inputFile.open(fileError);

        if(!inputFile.is_open()){
            fileError = fileError + ".csv";
            inputFile.close();
            inputFile.open(fileError);

            if(!inputFile.is_open()){
                //giving up
                std::cerr << "Error opening " << fileName << std::endl;
                return;
            }
        }
    }

    codes.clear();
    functionOrder.clear();
    std::string line;
    while(getline(inputFile,line)){
        std::stringstream ss(line);
        int pulseLength;
        std::string codeName;
        std::vector<int> currFunction;

        //get the name of the function
        std::getline(ss, codeName, ':');
        functionOrder.push_back(codeName);

        //get the timings
        while(ss >> pulseLength){
            currFunction.push_back(pulseLength);
        }

        //add these to the vector of all functions
        codes.push_back(std::move(currFunction));
    }   
}

void IrSender::getCodes(int fileNum){
    getCodes(files[fileNum]);
}

void IrSender::printFunctionOrder(){
    for (unsigned i = 0; i < functionOrder.size(); i++){
        std::cout << functionOrder.at(i) << ": " << i << std::endl;
    }
}

void IrSender::clearCodes(){
    codes.clear();
    functionOrder.clear();
}

void IrSender::sendIrCode(int index){
    for(unsigned i = 0; i < codes.at(i).size(); i++){
        //arduino stuff
    }
}