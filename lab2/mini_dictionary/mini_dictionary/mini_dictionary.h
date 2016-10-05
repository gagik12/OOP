#pragma once
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <Windows.h>

typedef std::map<std::string, std::string> Dictionary;

bool IsEmptyFile(std::string fileName);
Dictionary GetDictionaryFromFile(std::string const&dictionaryFile);
void ProcessingNewWords(std::string &newWord, Dictionary &dictionary, bool &isChangesInTheDictionary);
std::string FindTranslation(std::string &inputWord, Dictionary &dictionary);
void SaveChangesInFile(Dictionary const& dictionary, std::string const& dictionaryFileName);
void StartTranslation(Dictionary &dictionary, std::string const&dictionaryFileName);