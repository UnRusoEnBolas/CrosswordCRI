#include "CrosswordDeckCell.h"
#include <assert.h>

CrosswordDeckCell::CrosswordDeckCell(pair<int, int> coordinates, bool isActive) {
	this->coordinates = coordinates;
	this->active = isActive;
	if (isActive) this->letter = '-';
	else this->letter = '#';
}

void CrosswordDeckCell::setLetter(char letter) {
	//La cell ha de ser activa y no ha de tenir cap lletra assignada.
	assert(this->active == true);
	assert(this->set == false);

	this->letter = letter;
	this->set = true;
}

void CrosswordDeckCell::removeLetter() {
	//La cell ha de ser activa y ha de tenir alguna lletra asignada.
	assert(this->active == true);
	assert(this->set == false);

	this->letter = '-';
	this->set = false;
}

