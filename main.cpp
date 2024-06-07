#include <iostream>
#include <stdio.h>
#include <string.h>

std::string getUserInput() {
    std::string userInput;
    std::cout << "Please enter string to pigify: ";
    std::cin >> userInput;
    std::cout << "Thank you" << std::endl;
    return userInput;
}

// this will only work for individual words at the moment, damn it
std::string pigify(std::string inputString) {
    // IF CONS, MOVE TO END AND ADD AY
    // IF VOWEL, ADD YAY
    char vowelArr[6] = "aeiou";
    char consArr[22] = "bcdfghjklmnpqrstvwxyz";
    std::string piggedOutput = inputString;
    // loop through input string as characters until you reach a 
    // if character is in vowelArr do blah
    // if character is in consArr do blah
    // move char to end of inputString
    for (int i = 0; i < inputString.size(); i++) {
        if (strchr(consArr, inputString[i])) {
            piggedOutput = piggedOutput.substr(1, piggedOutput.length() - 1) + piggedOutput.front();
        }
        if (strchr(consArr, piggedOutput[0])) {
            piggedOutput += "ay";
            break;
        }
        if (strchr(consArr, inputString[0])) {
            piggedOutput += "yay";
            break;
        }
    }

    return piggedOutput;
}

int main() {
    std::cout << "PIG LATIN BOX" << std::endl;
    std::string userInput = getUserInput();
    std::cout << pigify(userInput);
    return 0;
}
