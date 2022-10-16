// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-06
// WS05
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#ifndef SDDS_SPELLCHECKER
#define SDDS_SPELLCHECKER

#include <string>

const auto ARR_SIZE = 6;

namespace sdds{
	class SpellChecker{
		std::string m_badWords[ARR_SIZE]{};
		std::string m_goodWords[ARR_SIZE]{};
		size_t      m_counter[ARR_SIZE]{};

	public:
		SpellChecker() {};
		SpellChecker(const char* filename);    //exception of misspelled words on the object
		void operator()(std::string& text);    //replace misspelled word
		void showStatistics(std::ostream& out) const; //display counter of misspelled word
	};
}

#endif // !SDDS_SPELLCHECKER



