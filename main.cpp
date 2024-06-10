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

// Function to check if a character is a vowel
bool isVowel(char ch) {
    char vowels[] = "aeiouAEIOU";
    return strchr(vowels, ch) != nullptr;
}

// this will only work for individual words at the moment, damn it
std::string pigify(std::string inputString) {
    if (isVowel(inputString[0])) {

    } else {

    }

    return piggedOutput;
}

int main() {
    std::cout << "PIG LATIN BOX" << std::endl;
    std::string userInput = getUserInput();
    std::cout << "Pigified: " << pigify(userInput) << std::endl;
    return 0;
}