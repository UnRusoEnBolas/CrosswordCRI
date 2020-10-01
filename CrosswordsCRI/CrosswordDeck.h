#include "CrosswordDeckCell.h"
#include "CrosswordGap.h"
#include <list>
#include <vector>
#pragma once
using namespace std;

class CrosswordDeck
{
	private:
		vector<vector<CrosswordDeckCell*>> deck;
		list<CrosswordGap*> gaps;
		int rows;
		int cols;
	public:
		CrosswordDeck(int rows, int cols, list<char> charsList);
		~CrosswordDeck();
		list<CrosswordGap*> getGaps() { return this->gaps; }
		list<CrosswordGap*> getHorizontalGaps();
		list<CrosswordGap*> getVerticalGaps();
		void printDeck();
};

