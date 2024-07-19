#include <string>
#include <fstream>
#include <iostream>
#include <map>

using std::string;

string unpigifyWord(const string &word, std::map<string, string> dictionary) {
    std::map<string, string>::iterator it;

    for (it = dictionary.begin(); it != dictionary.end(); ++it) {
        if (word == it->first) {
            return it->second;
        }
    }
    
    return word;
}

string unpigifySentence(string &InputSentence, std::map<string, string> dictionary) {

    // TODO
    return InputSentence;
}