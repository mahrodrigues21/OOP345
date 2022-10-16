// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-06
// WS05
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#ifndef SDDS_BOOK__H
#define SDDS_BOOK__H

#include <string>

namespace sdds{
	class Book{
		std::string m_author{};
		std::string m_title{};
		std::string m_countryPubli{};
		size_t      m_yearPubli = 0;
		double      m_priceBook = 0.0;
		std::string m_descBook{};

	public:
		Book() {};                         //default initialization
		const std::string& title() const;  //return title of the book
		const std::string& country() const; //return publication country
		const size_t& year() const;        //return publication year
		double& price();                   //return price by reference
		Book(const std::string& strBook);  //constructor extract book information
        
		friend std::ostream& operator<<(std::ostream& os, const Book& src); //friend helpers display book information

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_descBook);
		}
	};

}


#endif // !SDDS_BOOK__H


