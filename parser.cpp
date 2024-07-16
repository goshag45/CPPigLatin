#include <iostream>
#include <fstream> 
#include <string>

#include "functions.h"

// setup text file as json kinda?
// go through entire list
// pigify each word 
// write to json file as pigifiedword:originalword
// will have to write a json parses OH WELL

void ParseFile(std::string& fileName) {
    std::ifstream file(fileName);
    std::string word;
    if (file.is_open()) {    
        while (std::getline(file, word)) {
            // testing pigify from header
            std::cout << pigifyWord(word) << std::endl;
            // implement functionality here
        }
    } else {
        std::cerr << "Could not open file!" << std::endl;
    }
}

void GenerateDictionary(const std::string &fileName) {
    
}