#pragma once
#include "stdafx.h"
#include "var.h"

void ReadMap(std::ifstream &inputFile, std::ofstream &outputFile, Labirinth &labirinth, bool &wasError);
void PrintMap(std::ofstream &outputFile, Map &map, ComponentsMap const& componentsMap);
void FillTheMapWithZeros(Map &map);