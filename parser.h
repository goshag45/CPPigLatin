#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <map>

std::vector<std::string> ParseFile(std::string& fileName);
std::map<std::string, std::string> GenerateDictionary(std::string fileName);
void WriteToJSON(std::string outputFileName, std::map<std::string, std::string> dictionary);

#endif