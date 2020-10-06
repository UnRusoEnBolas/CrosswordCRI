#include "CrosswordDeckFileReader.h"
#include "CrosswordDeck.h"
#include "CrosswordDictionary.h"
#include <iostream>

int main()
{
    CrosswordDeckFileReader fileReader = CrosswordDeckFileReader(".\\data\\crossword_CB_v2.txt");
    CrosswordDeck crosswordDeck = CrosswordDeck(fileReader.getRows(), fileReader.getCols(), fileReader.getCharsList());
    CrosswordDictionary cd;
    cd.setDictionary(".\\data\\diccionari_CB.txt");
    crosswordDeck.printDeck();
    cout << "\n";

    //Proba tonta per veure que tot funciona!
    list<CrosswordGap*> gaps = crosswordDeck.getGaps();
    for (list<CrosswordGap*>::iterator it = gaps.begin(); it != gaps.end(); it++) {
        for (list<string>::iterator word = cd.getWords((*it)->getSize()).begin(); word != cd.getWords((*it)->getSize()).end(); word++) {
            if ((*it)->setWord((*word))) break;
        }
        crosswordDeck.printDeck();
        cout << "\n";
    }

    gaps.front()->removeWord();
    crosswordDeck.printDeck();
    cout << "\n";

    /*
    cout << "\n";
    cout << "Horizontal gaps in this crossword: " << crosswordDeck.getHorizontalGaps().size() << " - " << "Vertical gaps in this crossword: " << crosswordDeck.getVerticalGaps().size() << "\n";
    cout << "Total gaps in this crossword: " << crosswordDeck.getGaps().size() << "\n";

    //Comprovar funcionament diccionari
    cout << "PROVA printDictionary()" << endl;
    CrosswordDictionary cd;
    cd.setDictionary(".\\data\\diccionari_CB.txt");
    cd.printDictionary();

    //Obtenir llista de paraules de longitud n

    cout << "PROVA getWords()" << endl;
    std::list<string> l = cd.getWords(5);
    for (std::string& s : l)
    {
        cout << s << " ";
    }
    cout << endl;
    */
}
