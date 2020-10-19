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
		void setCrossedGaps();
		vector<CrosswordGap*> getHorizontalGaps();
		vector<CrosswordGap*> getVerticalGaps();
	public:
		CrosswordDeck(int rows, int cols, list<char> charsList, CrosswordDictionary* dictionary);
		~CrosswordDeck();
		vector<CrosswordGap*> getGaps() { return this->gaps; }
		void printDeck();
		void updateDomains(CrosswordGap* gap);
		void restoreDomains(CrosswordGap* gap);
		void orderGapsByCrossingGaps();
};

