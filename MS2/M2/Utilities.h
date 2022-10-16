// Name: Mayara Rodrigues
// Seneca Student ID: 118758200
// Seneca email: mrodrigues21@gmail.com	
// Date of completion: 11-27-2021
// PROJETCT - MS02
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES__H

#include <string>

namespace sdds
{
	class Utilities
	{
		//instance variable: specifies the length of the token, default value is 1. Datatype like member functions
		size_t m_widthField = 1u;

		//class variable: separates the tokens. datatype like class function
		static char m_delimiter;
	public:
		//set the width current object to the parameter value
		void setFieldWidth(size_t newWidth);
		//return the field of the current object
		size_t getFieldWidth() const;
		//extract a token: uses the delimiter to extract the next token (str), starting at next_pos.
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		//Class Function
		//set the delimiter received 
		static void setDelimiter(char newDelimiter);
		//returns the delimiter for this class.
		static char getDelimiter();
	};
}
#define SDDS_UTILITIES__H
#endif // !SDDS_UTILITIES__H





