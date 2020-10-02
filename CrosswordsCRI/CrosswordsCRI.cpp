#include "CrosswordDeckFileReader.h"
#include "CrosswordDeck.h"
#include "CrosswordDictionary.h"
#include <iostream>

int main()
{
    CrosswordDeckFileReader fileReader = CrosswordDeckFileReader(".\\data\\crossword_CB_v2.txt");
    CrosswordDeck crosswordDeck = CrosswordDeck(fileReader.getRows(), fileReader.getCols(), fileReader.getCharsList());
    crosswordDeck.printDeck();
    cout << "\n";
    cout << "Horizontal gaps in this crossword: " << crosswordDeck.getHorizontalGaps().size() << " - " << "Vertical gaps in this crossword: " << crosswordDeck.getVerticalGaps().size() << "\n";
    cout << "Total gaps in this crossword: " << crosswordDeck.getGaps().size() << "\n";

    //Comprovar funcionament diccionari
    CrosswordDictionary cd;
    cd.setDictionary(".\\data\\diccionari_CB.txt");
    cd.printDictionary();
}
