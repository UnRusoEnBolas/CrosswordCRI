#include "CrosswordDeckCell.h"
#include <assert.h>

CrosswordDeckCell::CrosswordDeckCell(pair<int, int> coordinates, bool isActive) {
	this->coordinates = coordinates;
	this->active = isActive;
	if (isActive) this->lettersStack.push('-');
	else this->lettersStack.push('#');
}

void CrosswordDeckCell::setLetter(char letter) {
	//La cell ha de ser activa.
	assert(this->active == true);
	this->lettersStack.push(letter);
}

void CrosswordDeckCell::removeLetter() {
	//La cell ha de ser activa y la pila ha de tenir un tamany >= 2.
	assert(this->active == true);
	assert(this->lettersStack.size() >= 2);
	this->lettersStack.pop();
}

char CrosswordDeckCell::getLetter() {
	return this->lettersStack.top();
}

