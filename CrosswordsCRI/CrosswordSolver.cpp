#include "CrosswordSolver.h"

CrosswordSolver::CrosswordSolver(CrosswordDeck* deck, CrosswordDictionary* dictionary) {
	this->deck = deck;
	this->dict = dictionary;
	this->totalGaps = deck->getGaps().size();
}

bool CrosswordSolver::solveCrossword_Backtracking() {
	if (this->filledGaps == this->totalGaps) return true;
	vector<string> possibleWords = this->deck->getGaps()[this->filledGaps]->getAvailableDomain();
	for (int idx = 0; idx < possibleWords.size(); idx++) {
		if (this->deck->getGaps()[this->filledGaps]->setWord(possibleWords[idx])) {
			this->filledGaps++;
			if (this->solveCrossword_Backtracking()) return true;
		}
	}
	this->filledGaps--;
	this->deck->getGaps()[this->filledGaps]->removeWord();
	return false;
}

bool CrosswordSolver::remainingGapsStillHaveDomain() {
	vector<CrosswordGap*> gaps = this->deck->getGaps();
	for (vector<CrosswordGap*>::iterator it = gaps.begin()+this->filledGaps; it != gaps.end(); it++) {
		if ((*it)->getAvailableDomain().size() == 0) {
			return false;
		}
	}
	return true;
}

bool CrosswordSolver::solveCrossword_Backtracking_WithForwardChecking() {
	if (this->filledGaps == this->totalGaps) return true;
	vector<string> possibleWords = this->deck->getGaps()[this->filledGaps]->getAvailableDomain();
	
	if (this->remainingGapsStillHaveDomain()) {
		for (int idx = 0; idx < possibleWords.size(); idx++) {
			if (this->deck->getGaps()[this->filledGaps]->setWord(possibleWords[idx])) {
				this->deck->updateDomains(this->deck->getGaps()[this->filledGaps]);
				this->filledGaps++;
				if (this->solveCrossword_Backtracking_WithForwardChecking()) return true;
			}
		}
	}

	this->filledGaps--;
	this->deck->getGaps()[this->filledGaps]->removeWord();
	this->deck->restoreDomains(this->deck->getGaps()[this->filledGaps]);
	return false;
}