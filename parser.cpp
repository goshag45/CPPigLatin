#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <map>
#include <iterator>

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
            outputVector.push_back(word);
        }
    } else {
        std::cerr << "Could not open file!" << std::endl;
    }
    return outputVector;
}

std::map<string, string> GenerateDictionary(string fileName) {
    vector<string> pigifiedVector;
    std::map<string, string> dictionary;

    pigifiedVector = ParseFile(fileName);
    for (const string &word : pigifiedVector) {
        string pigifiedWord = pigifyWord(word);
        dictionary.insert(std::make_pair(pigifiedWord, word));
    }

    return dictionary;
}

void WriteToJSON(string outputFileName, std::map<string, string> dictionary) {
    std::ofstream file(outputFileName);

    if (file.is_open()) {
        file << "{" << "\n";
        for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
            file << "\"" << it->first << "\"" << ":" << " \"" << it->second << "\"";
            if (std::next(it) != dictionary.end()) {
                file << ",";
            }
            file << "\n";
        }
        file << "}";
        file.close();
    } else {
        std::cerr << "Unable to create/open file: " << outputFileName << std::endl;
    }
}

// IF !READFROMJSON (NAME DICTIONARY?) PLEASE GENERATE PIGCTIONARY
std::map<string, string> ReadFromJSON(string fileName) {
    std::ofstream file(fileName);
    std::map<string, string> dictionary;

    if (file.is_open()) {

        file.close();
    } else {
        std::cerr << "Unable to create/open file: " << fileName << std::endl;
    }

    return dictionary;
}