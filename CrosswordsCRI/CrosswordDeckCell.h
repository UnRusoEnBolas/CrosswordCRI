#include <utility>
#pragma once
using namespace std;

class CrosswordDeckCell {
private:
	pair<int, int> coordinates;
	bool active;
	bool set = false;
	char letter;
public:
	CrosswordDeckCell(pair<int, int> coordinates, bool isActive);
	void setLetter(char letter);
	void removeLetter();
	bool isActive() { return this->active; }
	bool isSet() { return this->set; }
	char getLetter() { return this->letter; }
};