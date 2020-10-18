#include <string>
#include <list>
#include <vector>
#include "CrosswordDeckCell.h"
#pragma once
using namespace std;

enum class Direction {vertical, horizontal};

class CrosswordGap {
private:
	list<CrosswordDeckCell*> cells;
	list<pair<string, bool>> domain;
	Direction direction;
	list<pair<CrosswordGap, int>> crossedGaps;
public:
	CrosswordGap(list<CrosswordDeckCell*> cells, Direction direction, vector<string> domainWords);
	int getSize() { return this->cells.size(); }
	vector<string> getAvailableDomain();
	Direction getDirection() { return this->direction; }
	list<CrosswordDeckCell*> getCells() { return this->cells; }
	bool setWord(string word);
	string getWord();
	void removeWord();
	void addCrossedGaps(pair<CrosswordGap, int> crossedGap) { crossedGaps.push_back(crossedGap); }
};