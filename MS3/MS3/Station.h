// Name: Mayara Rodrigues
// Seneca Student ID: 118758200
// Seneca email: mrodrigues21@gmail.com	
// Date of completion: 12-04-2021
// PROJETCT - MS03
// I confirm that I am the only author of this file and the content was created entirely by me, based on my lasts WSs done and the MS01 and MS02.
//As reference https://www.cplusplus.com/reference/deque/deque/

#ifndef SDDS_STATION__H
#define  SDDS_STATION__H

#include <string>

namespace sdds
{
	class Station
	{
		//instance variables
		size_t m_idStation = 0u;
		std::string m_nameStation{};
		std::string m_descStation{};
		size_t m_noSerial = 0u;
		size_t m_noItem = 0u;

		//Class variables
		static size_t m_widthField;
		static size_t m_idgenetaror;

	public:
		//1 argument constructor, receives a reference(&) unmodifiable (const) single line
		Station(const std::string& src);
		//return the name of the current Station
		const std::string& getItemName() const;
		//returns the next serial number
		size_t getNextSerialNumber();
		//return the remaining quantity os items in the Station
		size_t getQuantity() const;
		//substract 1 from available quantity, a non-negative value
		void updateQuantity();
		//insert infomation into os
		void display(std::ostream& os, bool full) const;
	};
}


#endif // !SDDS_STATION__H

