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

std::string pigifyWord(std::string InputString) {
    if (isVowel(InputString[0])) {
        return InputString + "yay";
    } else {
        size_t pos = 0;
        while (pos < InputString.size() && !isVowel(InputString[pos])) {
            ++pos;
        }

        if (pos == InputString.size()) {
            return InputString + "ay";
        } else {
            return InputString.substr(pos) + InputString.substr(0, pos) + "ay";
        }
    }
}

std::string pigifySentence(std::string InputSentence) {
    if (strchr(InputSentence, " ") == nullptr) {
        return pigifyWord(InputSentence);
    }

    // got it from stack overflow, hope it works
    auto SplitList = std::find_if(str.begin(), str.end(), [] (const char element) -> bool {
                       return std::isspace(element) || std::ispunct(element);})
    
    for (int i = 0; i < SplitList; i++)
}

int main() {
    std::cout << "PIG LATIN BOX" << std::endl;
    std::string userInput = getUserInput();
    std::cout << "Pigified: " << pigifySentence(userInput) << std::endl;
    return 0;
}