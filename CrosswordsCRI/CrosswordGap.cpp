#include "CrosswordGap.h"

CrosswordGap::CrosswordGap(list<CrosswordDeckCell*> cells, Direction direction) {
	this->cells = cells;
	this->direction = direction;
}

bool CrosswordGap::setWord(string word) {
	if (word.size() != this->cells.size()) return false;

	int idx = 0;
	for (list<CrosswordDeckCell*>::iterator it = this->cells.begin(); it != this->cells.end(); it++) {
		char actualLetterInCell = (*it)->getLetter();
		if (actualLetterInCell != '-' && actualLetterInCell != word[idx]) return false;
		idx++;
	}
	
	idx = 0;
	for (list<CrosswordDeckCell*>::iterator it = this->cells.begin(); it != this->cells.end(); it++) {
		(*it)->setLetter(word[idx]);
		idx++;
	}
	return true;
}

string CrosswordGap::getWord() {
	string word;
	for (list<CrosswordDeckCell*>::iterator it = this->cells.begin(); it != this->cells.end(); it++) {
		word.push_back((*it)->getLetter());
	}
	return word;
}

void CrosswordGap::removeWord() {
	for (list<CrosswordDeckCell*>::iterator it = this->cells.begin(); it != this->cells.end(); it++) {
		(*it)->removeLetter();
	}
}