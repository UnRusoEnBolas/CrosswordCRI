#include "CrosswordDictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <exception>


CrosswordDictionary::~CrosswordDictionary()
{
	m_dictionary.clear();
}

/**
* setDictionary
* Aquesta funcio llegeix el fitxer de paraules i les emmagatzema en
  un diccionari amb par (long_paraula,llista de paraules amb longitud long_paraula)
* @param file_name : nom del fitxer de paraules ubicat a /data
*/
void CrosswordDictionary::setDictionary(std::string file_name)
{
	(m_llistes[0]).push_back("");
	assert(file_name != "");
	std::ifstream file;
	file.open(file_name);

	try
	{
		if (file.is_open())
		{
			std::string word;

			file >> word;

			while (!file.eof())
			{	
				emplaceWordtoList(word);
				//m_dictionary.emplace(word.length(),m_llistes[word.length()-1]);
				file >> word;
				//m_dictionary.emplace(word, word.length());
			}
			file.close();
		}

		for (size_t i = 0; i < MAX_LLISTES; ++i)
		{
			m_dictionary.emplace(i + 1, m_llistes[i]);
		}
	}
	catch (std::ifstream::failure& e)
	{
		std::cout << "Error opening/closing words file" << std::endl;
	}
}

/**
* printDictionary
* Aquesta funcio printa el diccionari de paraules per pantalla 
  amb el format longitud i --> llista de paraules de longitud i
*/

void CrosswordDictionary::printDictionary() 
{
	assert(!m_dictionary.empty());

	for (auto& p : m_dictionary)
	{
		std::cout << p.first << " --> " << " {";
		for (std::string& word : p.second )
		{
			std::cout << word << ", ";
		}
		std::cout << "}" << std::endl;
	}
}

/**
* emplaceWordtoList
* Aquesta funcio coloca cada paraula de longitud l a la seva respectiva llista
*/
void CrosswordDictionary::emplaceWordtoList(std::string& word)
{
	assert(word != "");
	
	m_llistes[word.length() - 1].push_back(word);

}

std::list<std::string>& CrosswordDictionary::getWords(int length)
{
	assert(length > 0);

	return m_llistes[length - 1];
}