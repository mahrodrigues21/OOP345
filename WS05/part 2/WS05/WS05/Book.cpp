// Student
// Name: Mayara Rodrigues
// Student Number: 118758200
// Student ID: mrodrigues21
// Date: 2021-11-06
// WS05
// I have done all the coding by myselfand only copied the code that my professor provided to complete my
// workshopsand assignments, and the references posted on WS assignment. 

#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"

using namespace std;

namespace sdds{
	const std::string& Book::title()const {  //return title of the book
		return m_title;
	}
	const std::string& Book::country()const { //return publication country
		return m_countryPubli;
	}
	const size_t& Book::year() const {       //return publication year
		return m_yearPubli;
	}
	double& Book::price() {                  //return price by reference
		return m_priceBook;
	}
	Book::Book(const std::string& strBook) { //constructor extract book information of a objects 
		std::string objBook = strBook;
		int pos = 0;

		//get author information
		//remove blank space in beginning of the string
		objBook.erase(0, objBook.find_first_not_of(" "));
		pos = objBook.find(",");
		m_author = objBook.substr(0, pos);
		//remove blank space at the end of the string
		m_author.erase(m_author.find_last_not_of(" ") + 1);

		//get title information
        //remove blank space in beginning of the string
		objBook.erase(0, pos + 1);
		objBook.erase(0, objBook.find_first_not_of(" "));
		pos = objBook.find(",");
		m_title = objBook.substr(0, pos);
		//remove blank space at the end of the string
		m_title.erase(m_title.find_last_not_of(" ") + 1);

		//get country information
        //remove blank space in beginning of the string
		objBook.erase(0, pos + 1);
		objBook.erase(0, objBook.find_first_not_of(" "));
		pos = objBook.find(",");
		m_countryPubli = objBook.substr(0, pos);
		//remove blank space at the end of the string
		m_countryPubli.erase(m_countryPubli.find_last_not_of(" ") + 1);

		//get price information
        //remove blank space in beginning of the string
		objBook.erase(0, pos + 1);
		objBook.erase(0, objBook.find_first_not_of(" "));
		pos = objBook.find(",");
		//change string to int
		m_priceBook = std::stod(objBook.substr(0, pos));

		//get year information
        //remove blank space in beginning of the string
		objBook.erase(0, pos + 1);
		objBook.erase(0, objBook.find_first_not_of(" "));
		pos = objBook.find(",");
		//change string to int
		m_yearPubli = std::stoi(objBook.substr(0, pos));

		//get description information
		//remove blank space in beginning of the string
		objBook.erase(0, pos + 1);
		objBook.erase(0, objBook.find_first_not_of(" "));
		m_descBook = objBook;
	}

	std::ostream& operator<<(std::ostream& os, const Book& src) { //friend helpers display book information
		os << setw(20) << right << src.m_author << " | ";
		os << setw(22) << src.title() << " | ";
		os << setw(5) << src.country() << " | ";
		os << setw(4) << src.year() << " | ";
		os << setw(6) << fixed << setprecision(2) << src.m_priceBook << " | ";
		os << left << src.m_descBook << endl;

		return os;
	} 
}


