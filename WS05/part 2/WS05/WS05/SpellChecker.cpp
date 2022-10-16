// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-06
// WS05
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "SpellChecker.h"

using namespace std;

namespace sdds{
	SpellChecker::SpellChecker(const char* filename) {    //exception of misspelled words on the object (WS02)
		int pos = 0;
		int cnt = 0;
	    std::string temp = {};
		std::ifstream fileIn(filename);

		//check if the file failed
		if (fileIn.is_open() == false){
			throw "Bad file name!";
		}
		else{
			for (auto i = 0; i < ARR_SIZE; i++){
				getline(fileIn, temp);
				//get bad word information
                //remove blank space in beginning of the string
				temp.erase(0, temp.find_first_not_of(" "));
				pos = temp.find(" ");
				m_badWords[cnt] = temp.substr(0, pos);

				//get good word information
                //remove blank space in beginning of the string
				temp.erase(0, pos + 1);
				temp.erase(0, temp.find_first_not_of(" "));
				pos = temp.find(" ");
				m_goodWords[cnt] = temp.substr(0, pos);

				//rising conter
				++cnt;
			}
		}
	}
	void SpellChecker::operator()(std::string& text) {    //replace misspelled word
		for (auto i = 0; i < ARR_SIZE; ++i){
			while (text.find(m_badWords[i]) != string::npos){
				//necessary use size() to know bites of the words it will be replace
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				++m_counter[i];
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out)const { //display counter of misspelled word
		out << "Spellchecker Statistics" << "\n";

		for (auto i = 0u; i < ARR_SIZE; i++){
			out << setw(15) << right << m_badWords[i] << ": ";
			out << m_counter[i] << " replacements";
			out << left << "\n";
		}
	}
}