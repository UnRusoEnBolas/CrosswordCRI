#include "CrosswordDeckFileReader.h"
#include "CrosswordDeck.h"
#include "CrosswordDictionary.h"
#include "CrosswordSolver.h"
#include <iostream>

int main()
{
    CrosswordDeckFileReader fileReader = CrosswordDeckFileReader("./data/crossword_CB_v2.txt");
    CrosswordDeck crosswordDeck = CrosswordDeck(fileReader.getRows(), fileReader.getCols(), fileReader.getCharsList());
    CrosswordDictionary crosswordDictionary = CrosswordDictionary("./data/diccionari_CB.txt");
    CrosswordSolver crosswordSolver = CrosswordSolver(&crosswordDeck, &crosswordDictionary);
    crosswordSolver.solveCrossword_Backtracking();
}
