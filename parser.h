#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

void GenerateDictionary(const std::string &fileName);
std::vector<std::string> ParseFile(std::string& fileName);

#endif