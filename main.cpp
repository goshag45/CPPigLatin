#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>

std::string getUserInput() {
    std::string userInput;
    std::cout << "Please enter string to pigify: ";
     std::getline(std::cin, userInput);
    std::cout << "Input collected succesfully" << std::endl;
    return userInput;
}

bool isVowel(char Character) {
    char vowels[] = "aeiouAEIOU";
    return strchr(vowels, Character) != nullptr;
}

std::string pigifyWord(const std::string &word) {
    if (word.empty()) {
        return "";
    }

    size_t pos = 0;
    std::string coreWord = word;
    std::string punctuation = "";

    while (pos < coreWord.size() && ispunct(coreWord.back())) {
        punctuation = coreWord.back() + punctuation;
        coreWord.pop_back();
    }

    if (isVowel(coreWord[0])) {
        return coreWord + "yay" + punctuation;
    } else {
        while (pos < coreWord.size() && !isVowel(coreWord[pos])) {
            ++pos;
        }

        if (pos == coreWord.size()) {
            return coreWord + "ay" + punctuation;
        } else {
            return coreWord.substr(pos) + coreWord.substr(0, pos) + "ay" + punctuation;
        }
    }
}

std::vector<std::string> SplitString(const std::string &str) {
    std::vector<std::string> words;
    std::string word;

    for (char ch : str) {
        if (std::isspace(ch) || std::ispunct(ch)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
            if (std::ispunct(ch)) {
                words.push_back(std::string(1, ch));
            }
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}


std::string pigifySentence(std::string &InputSentence) {
    std::vector<std::string> sentenceElements = SplitString(InputSentence);
    std::ostringstream oss;
    bool firstWord = true;

    
    for (std::string &element : sentenceElements) {
        if (!firstWord) {
            oss << " ";
        }
        if (std::ispunct(element[0])) {
            oss << element;
        } else {
            oss << pigifyWord(element);
        }
        firstWord = false;
    }

    return oss.str();
}

int main() {
    std::cout << "PIG LATIN BOX" << std::endl;
    std::string userInput = getUserInput();
    std::cout << "Pigified: " << pigifySentence(userInput) << std::endl;
    return 0;
}