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
    
    bool hasUpper = std::isupper(pigifiedWord[0]);
    // from pigify in main
    std::transform(pigifiedWord.begin(), pigifiedWord.end(), pigifiedWord.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    for (it = dictionary.begin(); it != dictionary.end(); ++it) {
        if (word == it->first) {
            return it->second;
        }
    }

    if (hasUpper) {
        pigifiedWord[0] = (char)std::toupper(pigifiedWord[0]);
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