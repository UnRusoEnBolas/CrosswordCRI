#include "CrosswordDeckCell.h"
#include "CrosswordGap.h"
#include "CrosswordDictionary.h"
#include <list>
#include <vector>
#pragma once
using namespace std;

class CrosswordDeck
{
	private:
		vector<vector<CrosswordDeckCell*>> deck;
		vector<CrosswordGap*> gaps;
		int rows;
		int cols;
	public:
		CrosswordDeck(int rows, int cols, list<char> charsList, CrosswordDictionary* dictionary);
		~CrosswordDeck();
		vector<CrosswordGap*> getGaps() { return this->gaps; }
		vector<CrosswordGap*> getHorizontalGaps();
		vector<CrosswordGap*> getVerticalGaps();
		void printDeck();

		void crossedGaps();
		void updateDomain(list<pair<CrosswordGap, int>> pair);

};

