#include <utility>
#include <stack>
#pragma once
using namespace std;

class CrosswordDeckCell {
private:
	pair<int, int> coordinates;
	stack<char> lettersStack;
	bool active;
public:
	CrosswordDeckCell(pair<int, int> coordinates, bool isActive);
	CrosswordDeckCell(const CrosswordDeckCell& cell1) { coordinates = cell1.coordinates; lettersStack = cell1.lettersStack; active = cell1.active; }
	void setLetter(char letter);
	void removeLetter();
	bool isActive() { return this->active; }
	char getLetter();
	pair<int, int> getCoords() { return this->coordinates; }
};