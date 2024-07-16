#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits>

#include "functions.h"

// I WILL NEED TO CREATE A DICTIONARY (10K?) MOST COMMON
// ENGLISH WORDS WITH ASSOCIATED PIGLATIN TRANSLATION
// header file dictionary is the way to go im thinking
// have to write program to parse txt of words

bool isVowel(char Character) {
    char vowels[] = "aeiouAEIOU";
    return strchr(vowels, Character) != nullptr;
}

// there is a better way!
std::string getUserInput(int variant) {
    std::string userInput;
    if (variant == 1) {
        std::cout << "Please enter string to pigify: ";
    } else if (variant == 2) {
        std::cout << "Please enter a pigged string: ";
    }    
    std::getline(std::cin, userInput);
    std::cout << "Input collected succesfully" << std::endl;
    return userInput;
}

std::vector<std::string> SplitString(const std::string &str) {
    std::vector<std::string> words;
    std::string word;

    for (char ch : str) {
        if (std::isspace(ch)) {
            // removes additional spaces (i think)
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        words.push_back(std::string(1, ch));
        } else if (std::ispunct(ch)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        words.push_back(std::string(1, ch));
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
std::string pigifyWord(const std::string &word) {
    if (word.empty()) {
        return "";
    }

    size_t pos = 0;
    std::string coreWord = word;
    std::string pigifiedWord;
    std::string punctuation = "";

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

std::string pigifySentence(std::string &InputSentence) {
    std::vector<std::string> sentenceElements = SplitString(InputSentence);
    std::ostringstream oss;
    bool firstWord = true;

    for (std::string &element : sentenceElements) {
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

std::string unpigifyWord(const std::string &word) {
    // TODO, might not even need
    return word;
}

std::string unpigifySentence(std::string &InputSentence) {
    // TODO
    return InputSentence;
}

//------------------------------------------------------------------------------//

int main() {
    int switchInput;

    std::cout << "PIG LATIN BOX" << std::endl;
    std::cout << "1. Pigify" << std::endl;
    std::cout << "2. Unpigify" << std::endl;
    std::cout << "Please enter your choice: ";
    std::cin >> switchInput;

    // clearing input buffer 
    while ((getchar()) != '\n');

    switch(switchInput) {
        case 1: {
            std::string userInput = getUserInput(1);
            std::cout << "Pigified: " << pigifySentence(userInput) << std::endl;
            break;
        }
        case 2: {
            std::string userInput = getUserInput(2);
            std::cout << "Un-Pigified: " << unpigifySentence(userInput) << std::endl;
            break;
        }
    }

    // cool workaround to not autoclose when i run in debug window!!
    //std::getchar();
    return 0;
}