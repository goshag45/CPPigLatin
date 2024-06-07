#include <iostream>

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
    char consArr[22] = "bcdfghjklmnpqrstvwxyz";
    char vowelArr[6] = "aeiou";
    std::string piggedOutput;
    // loop through input string as characters until you reach a 
    // if character is in consArr
    // move char to end of inputString
    for (int i = 0; i < inputString.size(); i++) {
        if (consArr.find(inputString[i])) {
            
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
