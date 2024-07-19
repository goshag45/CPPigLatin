#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include <algorithm>
#include <limits>
#include <sstream>
#include <vector>

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

    // TODO
    return InputSentence;
}