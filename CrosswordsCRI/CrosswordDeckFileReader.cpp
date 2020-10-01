#include "CrosswordDeckFileReader.h"

CrosswordDeckFileReader::CrosswordDeckFileReader(const char filePath[]) {
	this->fileStream = ifstream(filePath);

	this->rows = 1;
	this->cols = 1;
	
	char c = this->fileStream.get();
	while (this->fileStream.good()) {
		this->allCharacters.push_back(c);
		c = this->fileStream.get();
		if (c == '\t') { 
			if (this->rows == 1) this->cols++;
			c = this->fileStream.get();
		}
		else if (c == '\n') {
			this->rows++;
			c = this->fileStream.get();
		}
	}
	this->fileStream.close();

	//Sembla que s'afegeix un caracter extra al final!
	this->allCharacters.pop_back();
}

