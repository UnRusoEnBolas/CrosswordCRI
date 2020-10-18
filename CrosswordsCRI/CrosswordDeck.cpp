#include "CrosswordDeck.h"
#include <iostream>

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


void CrosswordDeck::crossedGaps() {
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

						pair<CrosswordGap, int> pair1((**it2), distance(horCells.begin(), itHorCells));
						(*it)->addCrossedGaps(pair1);

						pair<CrosswordGap, int> pair2((**it), distance(verCells.begin(), itVerCells));
						(*it2)->addCrossedGaps(pair2);
					}

				}
			}
		}
	}
}



// PARA ESTE METODO NO SE ME OCURRE UNA MANERA QUE NO SEA QUE VAYA A BUSCAR LOS CROSSED GAPS DEL CROSSED GAP QUE SE PASA POR PARAMETRO, 
// NO SE HASTA QUE PUNTO ES MEJOR PASAR UN GAP Y COMPROBARLO CON SUS CROSSED GAPS
/*
	void CrosswordDeck::updateDomain(CrosswordGap gap)
	{
		mirar sus crossed gaps y ver que letra hay en la cell que tienen en comun para quitar del dominio las palabras que no encajen
	}
*/


void CrosswordDeck::updateDomain(list<pair<CrosswordGap, int>> cross) {
	
	for (list<pair<CrosswordGap, int>>::iterator it = cross.begin(); it != cross.end(); it++) {
		CrosswordGap crossedGap = (*it).first;

		if (crossedGap.getWord() != " ") {
			list<pair<CrosswordGap, int>> crossList = crossedGap.getCrossedGaps();

			string crossedWord = crossedGap.getWord();

			int index = (*it).second;

		}
	}
}

