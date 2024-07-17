#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits>

#include "parser.h"
#include "unpigify.h"

using std::string;
using std::cout;
using std::endl;

bool isVowel(char Character) {
    char vowels[] = "aeiouAEIOU";
    return strchr(vowels, Character) != nullptr;
}

// there is a better way!
string getUserInput(int variant) {
    string userInput;
    if (variant == 1) {
        cout << "Please enter string to pigify: ";
    } else if (variant == 2) {
        cout << "Please enter a pigged string: ";
    } else if (variant == 3) {
        cout << "Please enter filename: ";
    }
    std::getline(std::cin, userInput);
    cout << "Input collected succesfully" << endl;
    return userInput;
}

std::vector<string> SplitString(const string &str) {
    std::vector<string> words;
    string word;

    for (char ch : str) {
        if (std::isspace(ch)) {
            // removes additional spaces (i think)
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        words.push_back(string(1, ch));
        } else if (std::ispunct(ch)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        words.push_back(string(1, ch));
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

//------------------------------------------------------------------------------//

//might b worth cleaning this up at some point - least nice function
string pigifyWord(const string &word) {
    if (word.empty()) {
        return "";
    }

    size_t pos = 0;
    string coreWord = word;
    string pigifiedWord;
    string punctuation = "";

    // check for punctutation 
    while (pos < coreWord.size() && ispunct(coreWord.back())) {
        punctuation = coreWord.back() + punctuation;
        coreWord.pop_back();
    }
    // check if first ch is uppercase and remember
    bool hasUpper = std::isupper(coreWord[0]);

    // this is cool https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
    std::transform(coreWord.begin(), coreWord.end(), coreWord.begin(), [](unsigned char c)
                   { return std::tolower(c); });

    if (isVowel(coreWord[0])) {
        pigifiedWord = coreWord + "yay";
    } else {
        while (pos < coreWord.size() && !isVowel(coreWord[pos])){
            ++pos;
        }

        if (pos == coreWord.size()) {
            pigifiedWord = coreWord + "ay";
        } else {
            pigifiedWord = coreWord.substr(pos) + coreWord.substr(0, pos) + "ay";
        }
    }

    if (hasUpper) {
        pigifiedWord[0] = (char) std::toupper(pigifiedWord[0]);
    }

    return pigifiedWord + punctuation;
}

string pigifySentence(string &InputSentence) {
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
            oss << pigifyWord(element);
            firstWord = false;
        }
    }

    return oss.str();
}

//------------------------------------------------------------------------------//

int main() {
    int switchInput;

    cout << "PIG LATIN BOX" << endl;
    cout << "1. Pigify" << endl;
    cout << "2. Unpigify" << endl;
    cout << "3. Generate Pigctionary" << endl;
    cout << "Please enter your choice: ";
    std::cin >> switchInput;

    // clearing input buffer 
    while ((getchar()) != '\n');

    switch(switchInput) {
        case 1: {
            string userInput = getUserInput(1);
            cout << "Pigified: " << pigifySentence(userInput) << endl;
            break;
        }
        case 2: {
            string userInput = getUserInput(2);
            cout << "Un-Pigified: " << unpigifySentence(userInput) << endl;
            break;
        }
        case 3: {
            string userInput = getUserInput(3);
            GenerateDictionary(userInput);
            cout << "Dictionary Generated!" << endl;
            break;
        }
    }

    // cool workaround to not autoclose when i run in debug window!!
    //std::getchar();
    return 0;
}