#include <string.h>
#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

#include "parser.h"
#include "unpigify.h"

using std::cout;
using std::endl;
using std::string;

bool isVowel(char Character) {
    char vowels[] = "aeiouAEIOU";
    return strchr(vowels, Character) != nullptr;
}

// there is a better way!
string getUserInput(int variant) {
    string userInput;
    if (variant == 1) {
        cout << "Please enter string to pigify: ";
    } else if (variant == 2) {
        cout << "Please enter filename to JSONify: ";
    } else if (variant == 3) {
        cout << "Please enter output filename: ";
    } else if (variant == 4) {
        cout << "Please enter a pigged string: ";
    }
    std::cout.flush();
    std::getline(std::cin, userInput);
    cout << "Input collected succesfully" << endl;
    return userInput;
}

std::vector<string> SplitString(const string &str) {
    std::vector<string> words;
    string word;

    for (char ch : str) {
        if (std::isspace(ch)) {
            // removes additional spaces (i think)
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
            words.push_back(string(1, ch));
        } else if (std::ispunct(ch)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
            words.push_back(string(1, ch));
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

//------------------------------------------------------------------------------//

// might b worth cleaning this up at some point - least nice function
string pigifyWord(const string &word) {
    if (word.empty()) {
        return "";
    }

    size_t pos = 0;
    string coreWord = word;
    string pigifiedWord;

    std::vector<int> capitalisedIndexes;
    bool hasUpper = false;    
    int capitalisedIndex;

    for (char c : coreWord) {
        if (std::isupper(c)) {
            hasUpper = true;
            capitalisedIndex = coreWord.find(c);
            capitalisedIndexes.push_back(capitalisedIndex);
        }
    }

    // this is cool
    // https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
    std::transform(coreWord.begin(), coreWord.end(), coreWord.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    if (isVowel(coreWord[0])) {
        pigifiedWord = coreWord + "yay";
    } else {
        while (pos < coreWord.size() && !isVowel(coreWord[pos])) {
            ++pos;
        }

        if (pos == coreWord.size()) {
            pigifiedWord = coreWord + "ay";
        } else {
            pigifiedWord = coreWord.substr(pos) + coreWord.substr(0, pos) + "ay";
        }
    }

    for (int i : capitalisedIndexes) {
        pigifiedWord[i] = (char)std::toupper(pigifiedWord[i]);
    }    

    capitalisedIndexes.clear();
    return pigifiedWord;
}

string pigifySentence(string &InputSentence) {
    std::vector<string> sentenceElements = SplitString(InputSentence);
    std::ostringstream oss;
    bool firstWord = true;

    for (string &element : sentenceElements) {
        if (std::isspace(element[0])) {
            oss << element;
        } else if (std::ispunct(element[0])) {
            oss << element;
        } else {
            oss << pigifyWord(element);
            firstWord = false;
        }
    }

    return oss.str();
}

//------------------------------------------------------------------------------//

int main() {
    bool isRunning = true;
    std::map<string, string> dictionary;

    while (isRunning) {
        int switchInput;
        cout << "-----------------------------------------" << endl;
        cout << "PIG LATIN BOX" << endl;
        cout << "1. Pigify" << endl;
        cout << "2. Generate Pigctionary" << endl;
        cout << "3. Unpigify" << endl;
        cout << "4. Exit" << endl;
        cout << "Please enter your choice: ";
        std::cin >> switchInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n');  // Clear input buffer

        switch (switchInput) {
            case 1: {
                string userInput = getUserInput(1);
                cout << "Pigified: " << pigifySentence(userInput) << endl;
                break;
            }
            case 2: {
                string targetFileName = getUserInput(2);
                string outputFileName = getUserInput(3);
                dictionary = GenerateDictionary(targetFileName);
                WriteToJSON(outputFileName, dictionary);
                cout << "Dictionary Generated!" << endl;
                break;
            }
            case 3: {
                string userInput = getUserInput(4);
                if (dictionary.empty()) {
                    cout << "Please create a dictionary first!" << endl;
                    break;
                }
                cout << "Un-Pigified: " << unpigifySentence(userInput, dictionary) << endl;
                break;
            }
            case 4: {
                cout << "Thank you for using!" << endl;
                isRunning = false;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    }

    // cool workaround to not autoclose when i run in debug window!!
    // std::getchar();
    return 0;
}