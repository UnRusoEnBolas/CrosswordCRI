#include "CrosswordGap.h"

CrosswordGap::CrosswordGap(list<CrosswordDeckCell*> cells, Direction direction) {
	this->cells = cells;
	this->direction = direction;
}