#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <map>
#include <iterator>

#include "main.h"

using std::string;
using std::vector;

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

vector<string> DecodeJSON(string fileName) {
    std::ofstream file(fileName);
    vector<string> outputVector;

    if (file.is_open()) {

        file.close();
    } else {
        std::cerr << "Unable to create/open file: " << fileName << std::endl;
    }

    return outputVector;
}

// IF !READFROMJSON (NAME DICTIONARY?) PLEASE GENERATE PIGCTIONARY
std::map<string, string> ReadFromJSON(string fileName) {
    std::map<string, string> dictionary;
    vector<string> words = DecodeJSON(fileName);

    while (!words.empty()) {
        string word1 = words[0];
        string word2 = words[1];
        dictionary.insert(std::make_pair(word1, word2));
        words.erase(words.begin(), words.begin() + 1);
    }

    return dictionary;
}