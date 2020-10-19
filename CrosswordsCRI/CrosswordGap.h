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
	list<pair<pair<string, bool>, CrosswordGap*>> domain;
	Direction direction;
	list<pair<CrosswordGap*, int>> crossedGaps;
public:
	CrosswordGap(list<CrosswordDeckCell*> cells, Direction direction, vector<string> domainWords);
	int getSize() { return this->cells.size(); }
	vector<string> getAvailableDomain();
	list<pair<pair<string, bool>, CrosswordGap*>>* getWholeDomain() { return &this->domain; }
	Direction getDirection() { return this->direction; }
	list<CrosswordDeckCell*> getCells() { return this->cells; }
	bool setWord(string word);
	string getWord();
	void removeWord();
	void addCrossedGaps(pair<CrosswordGap*, int> crossedGap) { crossedGaps.push_back(crossedGap); }
	list<pair<CrosswordGap*, int>>* getCrossedGaps() { return &(this->crossedGaps); }
	void updateDomain(char letter, int position, CrosswordGap* responsibleGap);
};