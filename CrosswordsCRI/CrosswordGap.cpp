#include "CrosswordGap.h"
#include <iostream>

using namespace std;

CrosswordGap::CrosswordGap(list<CrosswordDeckCell*> cells, Direction direction, vector<string> domainWords) {
	this->cells = cells;
	this->direction = direction;

	for (vector<string>::iterator it = domainWords.begin(); it != domainWords.end(); it++) {
		pair<string, bool> aux(*it, true);
		this->domain.push_back(pair<pair<string, bool>, CrosswordGap*>(aux, NULL));
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

	for (list<pair<pair<string, bool>, CrosswordGap*>>::iterator it = this->domain.begin(); it != this->domain.end(); it++) {
		if (it->first.first == word) it->first.second = false;
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

	string word = this->getWord();

	for (list<CrosswordDeckCell*>::iterator it = this->cells.begin(); it != this->cells.end(); it++) {
		(*it)->removeLetter();
	}

	for (list<pair<pair<string, bool>, CrosswordGap*>>::iterator it = this->domain.begin(); it != this->domain.end(); it++) {
		if (it->first.first == word) it->first.second = true;
	}
}

vector<string> CrosswordGap::getAvailableDomain() {
	vector<string> availableWords;
	for (list<pair<pair<string, bool>, CrosswordGap*>>::iterator it = this->domain.begin(); it != this->domain.end(); it++) {
		if (it->first.second == true) availableWords.push_back(it->first.first);
	}
	return availableWords;
}

void CrosswordGap::updateDomain(char letter, int position, CrosswordGap* responsibleGap) {
	for (list<pair<pair<string, bool>, CrosswordGap*>>::iterator it = this->domain.begin(); it != domain.end(); it++) {
		if (it->first.second) {
			if (it->first.first[position] != letter) {
				it->first.second = false;
				it->second = responsibleGap;
			}
		}
	}
}