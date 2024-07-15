#include <iostream>
#include <fstream> 
#include <string>

// setup text file as json kinda?
// go through entire list
// pigify each word 
// write to json file as pigifiedword:originalword
// will have to write a json parses OH WELL

std::string Pigify(const std::string &word) {
    std::string pigified = word;

    return word;
}

void ParseFile(std::string& fileName) {
    std::ifstream file(fileName);
    std::string word;
    if (file.is_open()) {    
        while (std::getline(file, word)) {
            std::cout << word << std::endl;
        }
    } else {
        std::cerr << "Could not open file!" << std::endl;
    }
}

std::string getUserInput() {
    std::string targetFile;
    std::cout << "Please enter name of file: ";
    std::cin >> targetFile;
    return targetFile;
}

int main() {
    std::string targetFile;
    targetFile = getUserInput();
    ParseFile(targetFile);

    return 0;
}