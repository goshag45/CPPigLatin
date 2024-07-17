#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <map>

#include "main.h"

using std::string;
using std::vector;

// setup text file as json kinda?
// go through entire list
// pigify each word 
// write to json file as pigifiedword:originalword
// will have to write a json parses OH WELL

vector<string> ParseFile(string& fileName) {
    std::ifstream file(fileName);
    string word;
    vector<string> outputVector;
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

void GenerateDictionary(const string &fileName) {
    vector<string> pigifiedVector;
    std::map<string, string> dictionary;
    string file = fileName;

    pigifiedVector = ParseFile(file);
    for (string word : pigifiedVector) {
        dictionary.insert(pigifyWord(word), word);
    }


}