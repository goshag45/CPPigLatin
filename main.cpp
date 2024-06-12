#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

std::string getUserInput() {
    std::string userInput;
    std::cout << "Please enter string to pigify: ";
    std::cin >> userInput;
    std::cout << "Input collected succesfully" << std::endl;
    return userInput;
}

bool isVowel(char Character) {
    char vowels[] = "aeiouAEIOU";
    return strchr(vowels, Character) != nullptr;
}

std::string pigifyWord(const std::string &word) {
    size_t pos = 0;
    std::string coreWord = word;
    std::string punctuation = "";

    while (pos < coreWord.size() && ispunct(coreWord.back())) {
        punctuation = coreWord.back() + punctuation;
        coreWord.pop_back();
    }

    if (isVowel(coreWord[0])) {
        return coreWord + "yay";
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

// why use pointers here?
std::vector<std:string> SplitString(const std::string& str) {


}


std::string pigifySentence(std::string InputSentence) {
    if (strchr(InputSentence, " ") == nullptr) {
        return pigifyWord(InputSentence);
    }


}

int main() {
    std::cout << "PIG LATIN BOX" << std::endl;
    std::string userInput = getUserInput();
    std::cout << "Pigified: " << pigifySentence(userInput) << std::endl;
    return 0;
}