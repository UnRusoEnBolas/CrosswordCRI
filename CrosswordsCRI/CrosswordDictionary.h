#include <unordered_map>
#include <list>
#include <vector>
#include <iostream>


/**
* CLASS CrosswordDictionary
* Classe que permet guardar les paraules del crossword i la seva longitud en un diccionari
* Conté una estructura unordered_map per emmagatzemar les paraules en una llista segons la seva longitud
* Conte un array de llistes per poder emmagtzemar paraules de una longitud a la seva respectiva llista
* Conte metodes per inicialitzar el diccionari amb un fitxer i per printar-lo per pantalla
* 
*/


class CrosswordDictionary
{
public:
	CrosswordDictionary() { m_llistes.resize(MAX_LLISTES); }
	~CrosswordDictionary();
	void setDictionary(std::string file_name);
    void printDictionary();
	void emplaceWordtoList(std::string& word);
	std::list<std::string>& getWords(int length);
	
private:
	static const int MAX_LLISTES = 15;
	std::unordered_map<int, std::list<std::string>> m_dictionary;
	std::vector<std::list<std::string>> m_llistes; //tamany maxim 15
};