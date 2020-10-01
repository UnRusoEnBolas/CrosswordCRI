#include <vector>
#include <list>
#include "CrosswordDeckCell.h"
#pragma once
using namespace std;

enum class Direction {vertical, horizontal};

class CrosswordGap {
private:
	list<CrosswordDeckCell*> cells;
	Direction direction;
public:
	CrosswordGap(list<CrosswordDeckCell*> cells, Direction direction);
	int getSize() { return this->cells.size(); }
	Direction getDirection() { return this->direction; }
	list<CrosswordDeckCell*> getCells() { return this->cells; }
	//Una funci� per assignar-hi una paraula (omplir amb una lletra tots els cells necessaris, si aquesta cell est� sent compartida no far�a falta assignar lletra). Utilitzar CrosswordDeckCell->setLetter(char lletra).
	//Una funci� per esborra la paraula (esborrar la lletra dels cells necessaris, si aquesta cell est� sent compartida no s'haur�a d'esborrar). Utilitzar CrosswordDeckCell->removeLetter().
};