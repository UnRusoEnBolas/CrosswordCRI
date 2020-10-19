#include "CrosswordDeckFileReader.h"
#include "CrosswordDeck.h"
#include "CrosswordDictionary.h"
#include "CrosswordSolver.h"
#include <iostream>
#include <chrono>

int main()
{

    cout << "Crossword CB using dictionary B -> WITHOUT forward checking: " << endl;
    CrosswordDeckFileReader fileReader = CrosswordDeckFileReader("./data/crossword_CB_v2.txt");
    CrosswordDictionary crosswordDictionary = CrosswordDictionary("./data/diccionari_CB.txt");
    CrosswordDeck crosswordDeck = CrosswordDeck(fileReader.getRows(), fileReader.getCols(), fileReader.getCharsList(), &crosswordDictionary);
    CrosswordSolver crosswordSolver = CrosswordSolver(&crosswordDeck, &crosswordDictionary);
    auto t_start = std::chrono::high_resolution_clock::now();
    crosswordSolver.solveCrossword_Backtracking();
    auto t_end = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    crosswordDeck.printDeck();
    cout << "In: " << elapsed_time_ms << " milliseconds" << endl;

    cout << endl;

    cout << "Crossword CB using dictionary A -> WITH forward checking: " << endl;
    fileReader = CrosswordDeckFileReader("./data/crossword_CB_v2.txt");
    crosswordDictionary = CrosswordDictionary("./data/diccionari_A.txt");
    crosswordDeck = CrosswordDeck(fileReader.getRows(), fileReader.getCols(), fileReader.getCharsList(), &crosswordDictionary);
    crosswordSolver = CrosswordSolver(&crosswordDeck, &crosswordDictionary);
    t_start = std::chrono::high_resolution_clock::now();
    crosswordSolver.solveCrossword_Backtracking_WithForwardChecking();
    t_end = std::chrono::high_resolution_clock::now();
    elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    crosswordDeck.printDeck();
    cout << "In: " << elapsed_time_ms << " milliseconds" << endl;

    cout << endl;

    cout << "Crossword A using dictionary A -> WITH forward checking: " << endl;
    fileReader = CrosswordDeckFileReader("./data/crossword_A_v2.txt");
    crosswordDictionary = CrosswordDictionary("./data/diccionari_A.txt");
    crosswordDeck = CrosswordDeck(fileReader.getRows(), fileReader.getCols(), fileReader.getCharsList(), &crosswordDictionary);
    crosswordSolver = CrosswordSolver(&crosswordDeck, &crosswordDictionary);
    crosswordDeck.orderGapsByCrossingGaps();
    t_start = std::chrono::high_resolution_clock::now();
    crosswordSolver.solveCrossword_Backtracking_WithForwardChecking();
    t_end = std::chrono::high_resolution_clock::now();
    elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    crosswordDeck.printDeck();
    cout << "In: " << elapsed_time_ms << " milliseconds" << endl;
}
