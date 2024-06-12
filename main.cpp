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

    if (isVowel(word[0])) {
        return word + "yay";
    } else {
        while (pos < word.size() && !isVowel(word[pos])) {
            ++pos;
        }

        if (pos == word.size()) {
            return word + "ay";
        } else {
            return word.substr(pos) + word.substr(0, pos) + "ay";
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