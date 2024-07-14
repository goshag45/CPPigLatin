#include <iostream>
#include <stdio.h>
#include <fstream> 
#include <string>

// setup text file as json kinda?
// go through entire list
// pigify each word 
// write to json file as pigifiedword:originalword
// will have to write a json parses OH WELL

std::string Pigify(const std::string &word) {
    std::string pigified = word;

    return word;
}

void ParseFile(std::string fileName) {
    std::ifstream file(fileName);
    std::string word;
    while (std::getline(fileName, word)) {

    }
}

int main() {

    return 0;
}