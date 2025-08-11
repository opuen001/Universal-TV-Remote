#include "IrSender.h"
#include <string>

void IrSender::modulation(unsigned int timeMicros) {
  unsigned long start = micros();
  while (micros() - start < timeMicros) {
    digitalWrite(LED_PIN, HIGH);
    delayMicroseconds(13);   // ~26µs total ON+OFF gives ~38kHz
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds(13);
  }
}

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
                std::cerr << "Error opening " << fileName << std::endl; //FIX: cerr not compatable for arduino.
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
    for(unsigned i = 0; i < codes.at(index).size(); i+= 2){
        modulation(codes.at(index).at(i)); //on with modulation

        // OFF
        digitalWrite(LED_PIN, LOW);
        if (i + 1 < codes.at(index).size()){
            delayMicroseconds(codes.at(index).at(i + 1));
        } else{
            std::cerr << "Odd number of timings" << std::endl; //FIX: cerr not compatable for arduino.
        }
    }
}

/*
void sendIRSignal() {
  for (int i = 0; i < 68; i += 2) {
    // ON with 38kHz modulation
    enableIROut(timing[i]);

    // OFF
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds(timing[i + 1]);
  }
}

void enableIROut(unsigned int timeMicros) {
  unsigned long start = micros();
  while (micros() - start < timeMicros) {
    digitalWrite(LED_PIN, HIGH);
    delayMicroseconds(13);   // ~26µs total ON+OFF gives ~38kHz
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds(13);
  }
}
  */