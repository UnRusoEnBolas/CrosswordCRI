#include "CrosswordSolver.h"

CrosswordSolver::CrosswordSolver(CrosswordDeck* deck, CrosswordDictionary* dictionary) {
	this->deck = deck;
	this->dict = dictionary;
	this->totalGaps = deck->getGaps().size();
}

bool CrosswordSolver::solveCrossword_Backtracking() {

	//this->deck->printDeck();

	if (this->filledGaps == this->totalGaps) return true;


	//vector<string> possibleWords = this->dict->getWords(this->deck->getGaps()[this->filledGaps]->getSize());
	vector<string> possibleWords = this->deck->getGaps()[this->filledGaps]->getAvailableDomain();
	for (int idx = 0; idx < possibleWords.size(); idx++) {
		if (this->deck->getGaps()[this->filledGaps]->setWord(possibleWords[idx])) {

			//cout << "INSERTING word: " << possibleWords[idx] << " in gap: " << this->filledGaps << endl;

			this->filledGaps++;
			if (this->solveCrossword_Backtracking()) return true;
		}

		//cout << "Not successful TRYING TO SET word: " << possibleWords[idx] << " in gap: " << this->filledGaps << endl;

	}

	this->filledGaps--;

	//cout << "Going back and DELETING word: " << this->deck->getGaps()[this->filledGaps]->getWord() << " from gap: " << this->filledGaps << endl;

	this->deck->getGaps()[this->filledGaps]->removeWord();
	return false;
}