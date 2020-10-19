#include "CrosswordDeckFileReader.h"
#include "CrosswordDeck.h"
#include "CrosswordDictionary.h"
#include "CrosswordSolver.h"
#include <iostream>

int main()
{
    CrosswordDeckFileReader fileReader = CrosswordDeckFileReader("./data/crossword_CB_v2.txt");
    CrosswordDictionary crosswordDictionary = CrosswordDictionary("./data/diccionari_CB.txt");
    CrosswordDeck crosswordDeck = CrosswordDeck(fileReader.getRows(), fileReader.getCols(), fileReader.getCharsList(), &crosswordDictionary);
    //crosswordDeck.crossedGaps();
    //vector<CrosswordGap*> tmp = crosswordDeck.getGaps();
    
    CrosswordSolver crosswordSolver = CrosswordSolver(&crosswordDeck, &crosswordDictionary);
    //crosswordSolver.solveCrossword_Backtracking();
    crosswordSolver.solveCrossword_Backtracking_WithForwardCheking();
    crosswordDeck.printDeck();
}
