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

bool isVowel(char ch) {
    char vowels[] = "aeiouAEIOU";
    return strchr(vowels, ch) != nullptr;
}

std::string pigify(std::string inputString) {
    if (isVowel(inputString[0])) {
        return inputString + "yay";
    } else {
        size_t pos = 0;
        while (pos < inputString.size() && !isVowel(inputString[pos])) {
            ++pos;
        }

        if (pos == inputString.size()) {
            return inputString + "ay";
        } else {
            return inputString.substr(pos) + inputString.substr(0, pos) + "ay";
        }
    }
}

int main() {
    std::cout << "PIG LATIN BOX" << std::endl;
    std::string userInput = getUserInput();
    std::cout << "Pigified: " << pigify(userInput) << std::endl;
    return 0;
}