#include "CrosswordDeck.h"
#include <iostream>

CrosswordDeck::CrosswordDeck(int rows, int cols, list<char> charsList) {
	this->rows = rows;
	this->cols = cols;

	this->deck = vector<vector<CrosswordDeckCell*>>(rows);

	//Donem a cada casella deck un apuntador a una cell.
	int i = 0;
	for (list<char>::iterator it = charsList.begin(); it != charsList.end(); it++) {
		if (*it == '#') this->deck[i / rows].push_back(new CrosswordDeckCell(pair<int, int>(i / rows, i % cols), false));
		else if (*it == '0') this->deck[i / rows].push_back(new CrosswordDeckCell(pair<int, int>(i / rows, i % cols), true));
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
				if (count > 1) this->gaps.push_back(new CrosswordGap(gap, Direction::horizontal));
				count = 0;
				gap.clear();
			}
		}
		if (count > 1) this->gaps.push_back(new CrosswordGap(gap, Direction::horizontal));
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
				if (count > 1) this->gaps.push_back(new CrosswordGap(gap, Direction::vertical));
				count = 0;
				gap.clear();
			}
		}
		if (count > 1) this->gaps.push_back(new CrosswordGap(gap, Direction::vertical));
	}
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

list<CrosswordGap*> CrosswordDeck::getHorizontalGaps() {
	list<CrosswordGap*> horizontalGaps;
	for (list<CrosswordGap*>::iterator it = this->gaps.begin(); it != this->gaps.end(); it++) {
		if ((*it)->getDirection() == Direction::horizontal) horizontalGaps.push_back(*it);
	}
	return horizontalGaps;
}

list<CrosswordGap*> CrosswordDeck::getVerticalGaps() {
	list<CrosswordGap*> verticalGaps;
	for (list<CrosswordGap*>::iterator it = this->gaps.begin(); it != this->gaps.end(); it++) {
		if ((*it)->getDirection() == Direction::vertical) verticalGaps.push_back(*it);
	}
	return verticalGaps;
}

