#include "CrosswordDeck.h"
#include "CrosswordDictionary.h"
#pragma once

class CrosswordSolver
{
private:
	CrosswordDeck* deck;
	CrosswordDictionary* dict;
	int totalGaps;
	int filledGaps = 0;
public:
	CrosswordSolver(CrosswordDeck* deck, CrosswordDictionary* dictionary);
	bool solveCrossword_Backtracking();
};

