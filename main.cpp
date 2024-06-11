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