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
	void setLetter(char letter);
	void removeLetter();
	bool isActive() { return this->active; }
	char getLetter();
};