#include <iostream>

std::string getUserInput() {
    std::string userInput;
    std::cout << "Please enter string to pigify: ";
    std::cin >> userInput;
    std::cout << "Thank you" << std::endl;
    return userInput;
}

std::string pigify(std::string inputString) {
    char consArr[22] = "bcdfghjklmnpqrstvwxyz";
    char vowelArr[6] = "aeiou";
    return "blah";
}

int main() {
    std::cout << "PIG LATIN BOX" << std::endl;
    std::string userInput = getUserInput();
    std::cout << pigify(userInput);
    return 0;
}
