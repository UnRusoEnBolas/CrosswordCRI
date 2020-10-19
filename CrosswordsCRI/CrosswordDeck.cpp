#include "CrosswordDeck.h"
#include <iostream>
#include <algorithm>

CrosswordDeck::CrosswordDeck(int rows, int cols, list<char> charsList, CrosswordDictionary* dictionary) {
	this->rows = rows;
	this->cols = cols;

	this->deck = vector<vector<CrosswordDeckCell*>>(rows);

	//Donem a cada casella deck un apuntador a una cell.
	int i = 0;
	for (list<char>::iterator it = charsList.begin(); it != charsList.end(); it++) {
		if (*it == '#') this->deck[i / rows].push_back(new CrosswordDeckCell(pair<int, int>(i / rows, i % cols), false));
		else if (*it == '0') this->deck[i / rows].push_back(new CrosswordDeckCell(pair<int, int>(i / rows, i % cols), true));
		else this->deck[i / rows].push_back(new CrosswordDeckCell(pair<int, int>(i / rows, i % cols), true));
		i++;
	}

	//Aquí treiem els gaps horitzontals i els guardem a l'atribut gaps.
	for (int x = 0; x < this->rows; x++) {
		int count = 0;
		list<CrosswordDeckCell*> gap;
		
		for (int y = 0; y < this->cols; y++) {
			if (this->deck[x][y]->isActive()) {
				count++;
				gap.push_back(deck[x][y]);
			}
			else {
				if (count > 1) this->gaps.push_back(new CrosswordGap(gap, Direction::horizontal, dictionary->getWords(count)));
				count = 0;
				gap.clear();
			}
		}
		if (count > 1) this->gaps.push_back(new CrosswordGap(gap, Direction::horizontal, dictionary->getWords(count)));
	}

	//Fem el mateix però per als gaps verticals.
	for (int x = 0; x < this->rows; x++) {
		int count = 0;
		list<CrosswordDeckCell*> gap;

		for (int y = 0; y < this->cols; y++) {
			if (this->deck[y][x]->isActive()) {
				count++;
				gap.push_back(deck[y][x]);
			}
			else {
				if (count > 1) this->gaps.push_back(new CrosswordGap(gap, Direction::vertical, dictionary->getWords(count)));
				count = 0;
				gap.clear();
			}
		}
		if (count > 1) this->gaps.push_back(new CrosswordGap(gap, Direction::vertical, dictionary->getWords(count)));
	}

	this->setCrossedGaps();
}

CrosswordDeck::~CrosswordDeck() {
	for (int i = 0; i < this->rows; i++) {
		this->deck[i].clear();
	}
	this->deck.clear();
	this->gaps.clear();
}

void CrosswordDeck::printDeck() {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			cout << this->deck[i][j]->getLetter() << " ";
		}
		cout << "\n";
	}
}

vector<CrosswordGap*> CrosswordDeck::getHorizontalGaps() {
	vector<CrosswordGap*> horizontalGaps;
 	for (vector<CrosswordGap*>::iterator it = this->gaps.begin(); it != this->gaps.end(); it++) {
		if ((*it)->getDirection() == Direction::horizontal) horizontalGaps.push_back(*it);
	}
	return horizontalGaps;
}

vector<CrosswordGap*> CrosswordDeck::getVerticalGaps() {
	vector<CrosswordGap*> verticalGaps;
	for (vector<CrosswordGap*>::iterator it = this->gaps.begin(); it != this->gaps.end(); it++) {
		if ((*it)->getDirection() == Direction::vertical) verticalGaps.push_back(*it);
	}
	return verticalGaps;
}


void CrosswordDeck::setCrossedGaps() {
	vector<CrosswordGap*> horizontalGaps = this->getHorizontalGaps();
	vector<CrosswordGap*> verticalGaps = this->getVerticalGaps();
	for (vector<CrosswordGap*>::iterator it = horizontalGaps.begin(); it != horizontalGaps.end(); it++) {
		for (vector<CrosswordGap*>::iterator it2 = verticalGaps.begin(); it2 != verticalGaps.end(); it2++) {

			list<CrosswordDeckCell*> horCells = (*it)->getCells();
			list<CrosswordDeckCell*> verCells = (*it2)->getCells();

			list<CrosswordDeckCell*>::iterator itHorCells;
			list<CrosswordDeckCell*>::iterator itVerCells;

			for (itHorCells = horCells.begin(); itHorCells != horCells.end(); itHorCells++) {
				for (itVerCells = verCells.begin(); itVerCells != verCells.end(); itVerCells++) {
					if ((*itVerCells)->getCoords() == (*itHorCells)->getCoords()) {

						pair<CrosswordGap*, int> pair1((*it2), distance(horCells.begin(), itHorCells));
						(*it)->addCrossedGaps(pair1);

						pair<CrosswordGap*, int> pair2((*it), distance(verCells.begin(), itVerCells));
						(*it2)->addCrossedGaps(pair2);
					}

				}
			}
		}
	}
}


void CrosswordDeck::updateDomains(CrosswordGap* gap) {
	string word = gap->getWord();
	for (list<pair<CrosswordGap*, int>>::iterator it = gap->getCrossedGaps()->begin(); it != gap->getCrossedGaps()->end(); it++) {
		int secondGapPosition = 0;
		for (list<pair<CrosswordGap*, int>>::iterator it2 = it->first->getCrossedGaps()->begin(); it2 != it->first->getCrossedGaps()->end(); it2++) {
			if (it2->first == it->first) secondGapPosition = it2->second;
		}
		char letter = word[it->second];
		it->first->updateDomain(letter, secondGapPosition, gap);
	}
}


void CrosswordDeck::restoreDomains(CrosswordGap* gap) {
	for (list<pair<CrosswordGap*, int>>::iterator it = gap->getCrossedGaps()->begin(); it != gap->getCrossedGaps()->end(); it++) {
		for (list<pair<pair<string, bool>, CrosswordGap*>>::iterator domainIt = it->first->getWholeDomain()->begin(); domainIt != it->first->getWholeDomain()->end(); domainIt++) {
			if (domainIt->second != NULL && domainIt->second == gap) {
				domainIt->second = NULL;
				domainIt->first.second = true;
			}
		}
	}
}


bool myfunction(CrosswordGap* i, CrosswordGap* j) { return (i->getCrossedGaps() < j->getCrossedGaps()); }

void CrosswordDeck::orderGapsByCrossingGaps() {
	std::sort(this->gaps.begin(), this->gaps.end(), myfunction);
}