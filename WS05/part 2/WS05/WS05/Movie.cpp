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
#include "Movie.h"

using namespace std;
namespace sdds{
	const std::string& Movie::title() const {   //return title of the movie
		return m_title;
	}
	Movie::Movie(const std::string& strMovie) { //extract movie information (WS4 as reference)
		std::string objMovie = strMovie;
		int pos = 0;

		//get title information
		//remove blank space in beginning of the string
		objMovie.erase(0, objMovie.find_first_not_of(" "));
		pos = objMovie.find(",");
		m_title = objMovie.substr(0, pos);
		//remove blank space at the end of the string
		m_title.erase(m_title.find_last_not_of(" ") + 1);

		//get year information
		//remove blank space in beginning of the string
		objMovie.erase(0, pos + 1);
		objMovie.erase(0, objMovie.find_first_not_of(" "));
		pos = objMovie.find(",");
		m_yearRel = std::stoi(objMovie.substr(0, pos));

		//get country information
		//remove blank space in beginning of the string
		objMovie.erase(0, pos + 1);
		objMovie.erase(0, objMovie.find_first_not_of(" "));
		m_descMovie = objMovie;
		
	}
	std::ostream& operator<<(std::ostream& os, const Movie& src){ //friend helpers display book information
		os << setw(40) << right << src.m_title << " | ";
		os << left << setw(4) << src.m_yearRel << " | " << src.m_descMovie << "\n";

		return os;
	}
}
