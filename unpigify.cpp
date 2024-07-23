#include <algorithm>  // for std::transform
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "main.h"

using std::string;

string unpigifyWord(const string &word, std::map<string, string> dictionary) {
    std::map<string, string>::iterator it;
    string unpigifiedWord = word;

    // this is so inefficient lmao
    // fix this dawg
    for (it = dictionary.begin(); it != dictionary.end(); ++it) {
        if (word == it->first) {
            return it->second;
        }
    }

    return unpigifiedWord;
}

string unpigifySentence(string &InputSentence, std::map<string, string> dictionary) {
    std::vector<string> sentenceElements = SplitString(InputSentence);
    std::ostringstream oss;
    bool firstWord = true;

    for (string word : sentenceElements) {
        std::transform(word.begin(), word.end(), word.begin(), 
            [](unsigned char c) { return std::tolower(c); });
    }

    for (string &element : sentenceElements) {
        if (std::isspace(element[0])) {
            oss << element;
        } else if (std::ispunct(element[0])) {
            oss << element;
        } else {
            if (!firstWord) {
                oss << " ";
            }
            oss << unpigifyWord(element, dictionary);
            firstWord = false;
        }
    }

    return oss.str();
}