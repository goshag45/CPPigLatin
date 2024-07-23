#include <algorithm>  // for std::transform
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "main.h"

using std::string;

string unpigifyWord(const string &word, const std::map<string, string> &dictionary) {
    string unpigifiedWord = word;
    string tempWord = word;
    bool hasUpper = false;
    std::vector<int> capitalisedIndexes;

    for (char c : tempWord) {
        if (std::isupper(c)) {
            hasUpper = true;
            capitalisedIndexes.push_back(word.find(c));
        }
    }

    std::transform(tempWord.begin(), tempWord.end(), tempWord.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    auto it = dictionary.find(tempWord);
    if (it != dictionary.end()) {
        unpigifiedWord = it->second;
    }

    for (int i : capitalisedIndexes) {
        unpigifiedWord[i] = (char)std::toupper(unpigifiedWord[i]);
    }

    return unpigifiedWord;
}

string unpigifySentence(string &InputSentence, std::map<string, string> &dictionary) {
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