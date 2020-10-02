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
  un diccionari amb par (paraula,longitud_paraula)
* @param file_name : nom del fitxer de paraules ubicat a /data
*/
void CrosswordDictionary::setDictionary(std::string file_name)
{
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
				m_dictionary.emplace(word, word.length());
				file >> word;
				//m_dictionary.emplace(word, word.length());
			}
			file.close();
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
  amb el format paraula --> longitud
*/

void CrosswordDictionary::printDictionary() 
{
	assert(!m_dictionary.empty());

	for (auto& p : m_dictionary)
	{
		std::cout << p.first << " --> " << p.second << std::endl;
	}
}