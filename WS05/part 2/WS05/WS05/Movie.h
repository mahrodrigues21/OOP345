// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-06
// WS05
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#ifndef SDDS_MOVIE__H
#define SDDS_MOVIE__H

#include <string>

namespace sdds{
	class Movie{
		std::string m_title{};
		size_t      m_yearRel = 0;
		std::string m_descMovie{};

	public:
		Movie() {};                         //default constructor
		const std::string& title() const;   //return title of the movie
		Movie(const std::string& strMovie); //extract movie information

		//template function
		template<typename T>
		void fixSpelling(T& spellChecker) {  
			spellChecker(m_title);
			spellChecker(m_descMovie);
		}

		friend std::ostream& operator<<(std::ostream& os, const Movie& src); //friend helpers display book information
	};
}

#endif // !SDDS_MOVIE__H



