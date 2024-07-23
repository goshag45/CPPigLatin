#include <string>
#include <iostream>
#include <map>
#include <algorithm> // for std::transform
#include <vector>
#include <sstream>

#include "main.h"

using std::string;

string unpigifyWord(const string &word, std::map<string, string> dictionary) {
    std::map<string, string>::iterator it;
    string pigifiedWord = word;

    // this is so inefficient lmao 
    // fix this dawg
    for (it = dictionary.begin(); it != dictionary.end(); ++it) {
        if (word == it->first) {
            return it->second;
        }
    }

    return word;
}

string unpigifySentence(string &InputSentence, std::map<string, string> dictionary) {
    std::vector<string> sentenceElements = SplitString(InputSentence);
    std::ostringstream oss;
    bool firstWord = true;

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