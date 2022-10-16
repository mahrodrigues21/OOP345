// Name: Mayara Rodrigues
// Seneca Student ID: 118758200
// Seneca email: mrodrigues21@gmail.com	
// Date of completion: 12-04-2021
// PROJETCT - MS03
// I confirm that I am the only author of this file and the content was created entirely by me, based on my lasts WSs done and the MS01 and MS02.
//As reference https://www.cplusplus.com/reference/deque/deque/

#include <string>
#include "Utilities.h"

using namespace std;

namespace sdds{
	//class member definition. As private needs to insert the module even it is the same module
	char Utilities::m_delimiter = {};

	//set the width current object to the parameter value
	void Utilities::setFieldWidth(size_t newWidth){
		if (newWidth > 1)
			m_widthField = newWidth;
	}
	//return the field of the current object
	size_t Utilities::getFieldWidth() const{
		return m_widthField;
	}
	//extract a token: uses the delimiter to extract the next token (str), starting at next_pos.
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
		//receives the next_pos parameter
		size_t new_pos = 0u;
		std::string token{};

		//find the next next position of the delimiter
		new_pos = str.find(m_delimiter, next_pos);

		if ((new_pos == next_pos) || (new_pos == 0)){ // there is no token to extract - if new_pos is 0 it means no characters to get.
			more = false;
			throw " Token is not found\n";
		}
		//it was a looping when started the utilities parts then a search to compare my length new_pos with the end of the string
		//npos means "until the end of the string", it's also a size_t datatype
		else if (new_pos == string::npos){
			//extract token starting the next_pos until new_pos
			token = str.substr(next_pos, new_pos);
			//to stop the read a string
			more = false;

			//update m_widthField if it is less then token
			if (m_widthField < token.length())
				m_widthField = token.length();
		}
		else{
			//extract token starting the next_pos until new_pos
			//subtrac the actual position to last position to get the length of the field
			new_pos -= next_pos;
			token = str.substr(next_pos, new_pos);
			//next_pos + new_pos + 1 
			next_pos += new_pos + 1;
			more = true;

			//update m_widthField if it is less then token
			if (m_widthField < token.length())
				m_widthField = token.length();
		}
		return token;
	}
	//Class Function - remove the static
	//set the delimiter received 
	void Utilities::setDelimiter(char newDelimiter){
		m_delimiter = newDelimiter;
	}
	//returns the delimiter for this class.
	char Utilities::getDelimiter(){
		return m_delimiter;
	}
}
