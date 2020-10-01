#include <iostream>
#include <fstream>
#include <list>
#pragma once
using namespace std;

class CrosswordDeckFileReader
{
private:
	ifstream fileStream;
	int rows;
	int cols;
	list<char> allCharacters;
public:
	CrosswordDeckFileReader(const char filePath[]);
	int getRows() { return this->rows; }
	int getCols() { return this->cols; }
	list<char>  getCharsList() { return this->allCharacters; }
};

