#include <unordered_map>
#include <iostream>

/**
* CLASS CrosswordDictionary
* Classe que permet guardar les paraules del crossword i la seva longitud en un diccionari
* Conté una estructura unordered_map per emmagatzemar les paraules i la seva longitud
* Conte metodes per inicialitzar el diccionari amb un fitxer i per printar-lo per pantalla
* 
*/


class CrosswordDictionary
{
public:
	CrosswordDictionary() {}
	~CrosswordDictionary();
	void setDictionary(std::string file_name);
    void printDictionary();
private:
	std::unordered_map<std::string, int> m_dictionary;
};