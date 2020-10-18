#include "CrosswordGap.h"
#include <iostream>

using namespace std;

CrosswordGap::CrosswordGap(list<CrosswordDeckCell*> cells, Direction direction, vector<string> domainWords) {
	this->cells = cells;
	this->direction = direction;

	for (vector<string>::iterator it = domainWords.begin(); it != domainWords.end(); it++) {
		this->domain.push_back(pair<string, bool>(*it, true));
	}
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

vector<string> CrosswordGap::getAvailableDomain() {
	vector<string> availableWords;
	for (list<pair<string, bool>>::iterator it = this->domain.begin(); it != this->domain.end(); it++) {
		if ((*it).second == true) availableWords.push_back((*it).first);
	}
	return availableWords;
}

