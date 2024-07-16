#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

#include "main.h"

// setup text file as json kinda?
// go through entire list
// pigify each word 
// write to json file as pigifiedword:originalword
// will have to write a json parses OH WELL

std::vector<std::string> ParseFile(std::string& fileName) {
    std::ifstream file(fileName);
    std::string word;
    std::vector<std::string> outputVector;
    if (file.is_open()) {    
        while (std::getline(file, word)) {
            // implement functionality here
            // need to push each word to vector!
            outputVector.push_back(pigifyWord(word));
        }
    } else {
        std::cerr << "Could not open file!" << std::endl;
    }
    return outputVector;
}

void GenerateDictionary(const std::string &fileName) {
    
}