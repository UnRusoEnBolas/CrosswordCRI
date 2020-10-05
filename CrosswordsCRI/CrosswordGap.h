#include <string>
#include <list>
#include "CrosswordDeckCell.h"
#pragma once
using namespace std;

enum class Direction {vertical, horizontal};

class CrosswordGap {
private:
	list<CrosswordDeckCell*> cells;
	Direction direction;
public:
	CrosswordGap(list<CrosswordDeckCell*> cells, Direction direction);
	int getSize() { return this->cells.size(); }
	Direction getDirection() { return this->direction; }
	list<CrosswordDeckCell*> getCells() { return this->cells; }
	bool setWord(string word);
	string getWord();
	void removeWord();
};